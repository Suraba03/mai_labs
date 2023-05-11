import numpy as np

class Setka:
    def __init__(self):
        pass
    
    def forward_pass(self):
        pass

    def another_func(self):
        pass

# non linear functions

def elu(x, u):
    if x >= 0:
        return x
    else:
        return u*(np.exp(x) - 1)

def elu_prime(x, u):
    if x >= 0:
        return 1
    else:
        return elu(x, u) + u

def ReLu(x):
    if x < 0:
        return 0
    else:
        return x

def LRelu(x):
    if x < 0:
        return 0.01 * x
    else:
        return x

def PRelu(x, u):
    if x < 0:
        return u*x
    else:
        return x

class Softmax:
    def forward(self,z):
        self.z = z
        zmax = z.max(axis=1,keepdims=True)
        expz = np.exp(z-zmax)
        Z = expz.sum(axis=1,keepdims=True)
        return expz / Z
    def backward(self,dp):
        p = self.forward(self.z)
        pdp = p * dp
        return pdp - p * pdp.sum(axis=1, keepdims=True)
    
def sigmoid(x):
  return 1.0 / (1.0 + np.exp(-x))

def sigmoid_derivative(x):
  return x * (1.0 - x)

# losses

def cross_ent(y_, y): # pred, true
    t = 1 if y > 0.5 else 0
    return -t * np.log(y_) - (1 - t) * np.log(1 - y_)
    
class CrossEntropyLoss:
    def forward(self,p,y):
        self.p = p
        self.y = y
        p_of_y = p[np.arange(len(y)), y]
        log_prob = np.log(p_of_y)
        return -log_prob.mean()
    def backward(self,loss):
        dlog_softmax = np.zeros_like(self.p)
        dlog_softmax[np.arange(len(self.y)), self.y] -= 1.0/len(self.y)
        return dlog_softmax / self.p

def zero_one(d):
    if d < 0:
        return 1
    return 0

zero_one_v = np.vectorize(zero_one)

def logistic_loss(fx):
    y = 1
    return 1 / np.log(2) * np.log(1 + np.exp(-y * fx))

# layers

class Linear:
    def __init__(self,nin,nout):
        self.W = np.random.normal(0, 1.0/np.sqrt(nin), (nout, nin))
        self.b = np.zeros((1,nout))
        self.dW = np.zeros_like(self.W)
        self.db = np.zeros_like(self.b)
        
    def forward(self, x):
        self.x=x
        return np.dot(x, self.W.T) + self.b
    
    def backward(self, dz):
        dx = np.dot(dz, self.W)
        dW = np.dot(dz.T, self.x)
        db = dz.sum(axis=0)
        self.dW = dW
        self.db = db
        return dx
    
    def update(self,lr):
        self.W -= lr*self.dW
        self.b -= lr*self.db

# net class

class NeuralNet:
    def __init__(self):
        self.layers = []
    
    def add(self,l):
        self.layers.append(l)
        
    def forward(self,x):
        for l in self.layers:
            x = l.forward(x)
        return x
    
    def backward(self,z):
        for l in self.layers[::-1]:
            z = l.backward(z)
        return z
    
    def update(self,lr):
        for l in self.layers:
            if 'update' in l.__dir__():
                l.update(lr)
