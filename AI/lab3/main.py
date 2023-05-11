import nn
import dataload

import seaborn as sns
from sklearn.datasets import make_moons

import torch
from torch.utils.data import TensorDataset, DataLoader
import torchvision.transforms as T

import matplotlib.pyplot as plt 
from matplotlib import gridspec
from sklearn.datasets import make_classification
import numpy as np

np.random.seed(0)
import random


# load data

n = 1000
X, Y = make_moons(n_samples=n, random_state=42, noise=0.1)

X = X.astype(np.float32)
Y = Y.astype(np.int32)

X_train, X_test = np.split(X, [n * 8 // 10])
y_train, y_test = np.split(Y, [n * 8 // 10])

# define layer of simple nn

lin = nn.Linear(2,2)
softmax = nn.Softmax()
cross_ent_loss = nn.CrossEntropyLoss()

# train loop for one layer nn

pred = np.argmax(lin.forward(X_train),axis=1)
acc = (pred==y_train).mean()
print("Initial accuracy: ",acc)

batch_size=4
dataloader = dataload.generate_batches(X_train, y_train, batch_size)

for x_batch, y_batch in dataloader:
    # forward pass
    z = lin.forward(x_batch)
    p = softmax.forward(z)
    loss = cross_ent_loss.forward(p,y_batch)
    
    # backward pass
    dp = cross_ent_loss.backward(loss)
    dz = softmax.backward(dp)
    dx = lin.backward(dz)
    lin.update(0.1)

# validation

pred = np.argmax(lin.forward(X_train),axis=1)
acc = (pred==y_train).mean()
print("Final accuracy: ",acc)


# more intricate nn 

print()
print()
print("bigger nn")
print()
print()

net = nn.NeuralNet()
net.add(nn.Linear(2,64))
net.add(nn.Linear(64,70))
net.add(nn.Linear(70,80))
net.add(nn.Linear(80,90))
net.add(nn.Linear(90,2))
net.add(nn.Softmax())
loss = nn.CrossEntropyLoss()

def get_loss_acc(x,y,loss=nn.CrossEntropyLoss()):
    p = net.forward(x)
    l = loss.forward(p,y)
    pred = np.argmax(p,axis=1)
    acc = (pred==y).mean()
    return l,acc

print("Initial loss={}, accuracy={}: ".format(*get_loss_acc(X_train,y_train)))


def train_epoch(net, X_train, y_train, loss=nn.CrossEntropyLoss(), batch_size=4, lr=0.1):
    dataloader = dataload.generate_batches(X_train, y_train, batch_size)
    
    for x_batch, y_batch in dataloader:
        p = net.forward(x_batch)
        l = loss.forward(p,y_batch)
        dp = loss.backward(l)
        dx = net.backward(dp)
        net.update(lr)
 
train_epoch(net,X_train,y_train)
        
print("Final loss={}, accuracy={}: ".format(*get_loss_acc(X_train,y_train)))
print("Test loss={}, accuracy={}: ".format(*get_loss_acc(X_test,y_test)))


# MNIST

print()
print()
print("MNIST data")
print()
print()

import os
from torchvision.datasets import MNIST
import torchvision.transforms as tfs

data_tfs = tfs.Compose([
    tfs.ToTensor(),
    tfs.Normalize((0.5), (0.5)),
    T.Lambda(lambda x: torch.flatten(x))
])

root = './'
train_dataset = MNIST(root, train=True,  transform=data_tfs, download=True)
val_dataset  = MNIST(root, train=False, transform=data_tfs, download=True)

train_dataloader = DataLoader(train_dataset, batch_size=128)
valid_dataloader = DataLoader(val_dataset, batch_size=128)


net1 = nn.NeuralNet()
net1.add(nn.Linear(784,64))
net1.add(nn.Linear(64,80))
net1.add(nn.Linear(80,100))
net1.add(nn.Linear(100,10))
net1.add(nn.Softmax())

loss=nn.CrossEntropyLoss()
lr=0.1

max_epochs = 10
for epoch in range(max_epochs):
    for x_batch, y_batch in train_dataloader:
        p = net1.forward(x_batch)
        l = loss.forward(p,y_batch)
        dp = loss.backward(l)
        dx = net1.backward(dp)
        net1.update(lr)

    print("Final loss={}, accuracy={}: ".format(*get_loss_acc(X_train,y_train)))

print("Test loss={}, accuracy={}: ".format(*get_loss_acc(X_test,y_test)))