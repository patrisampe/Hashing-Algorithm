# -*- coding: utf-8 -*-
import pandas as pd
from collections import Counter
from pandas import *
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from pylab import *
import csv
import numpy as np
from pandas import Series, DataFrame
import pandas as p
import matplotlib.pyplot as plt
from matplotlib.pyplot import hist
from pylab import randn, hist
import matplotlib.pyplot as plt
import numpy 
import pylab 
from numpy import * 
from pylab import * 
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.pyplot as plt
import re
import numpy as n




di = 100
te = 3*di
pp1= PdfPages('PlotsHashTable.pdf')
n = 2;
while(n>0):
    
    
    if(n == 1):
        grp= pd.read_csv('resultat100.csv', header=0)   
        di= 100
        te= 3*di
    else:
        grp= pd.read_csv('resultat1000.csv', header=0)   
        di= 1000
        te= 9*di
        
    fig, ax = plt.subplots()
    ax = plt.plot(grp['M'],grp['tempscreacio'])
    
    title("M vs temps de creacio. Mida diccionari:"+str(di) +" Mida text:"+ str(te))
    xlabel("M")
    ylabel("Temps de creacio (s)") 
    pp1.savefig() 
    
    fig, ax = plt.subplots()
    ax = plt.plot(grp['M'],grp['tempsbocom'])
    
    title("M vs temps de busqueda si encerta. Mida diccionari:"+str(di) +" Mida text:"+ str(te))
    xlabel("M")
    ylabel("Temps de busqueda si encerta (s)") 
    pp1.savefig() 
    
    fig, ax = plt.subplots()
    ax = plt.plot(grp['M'],grp['tempsdolcom'])
    
    title("M vs temps de busqueda si falla. Mida diccionari:"+str(di) +" Mida text:"+ str(te))
    xlabel("M")
    ylabel("Temps de busqueda si falla (s)") 
    pp1.savefig() 
    
    fig, ax = plt.subplots()
    ax = plt.plot(grp['M'],grp['compdol'])
    
    title("M vs comparacions de claus si falla. Mida diccionari:"+str(di) +" Mida text:"+ str(te))
    xlabel("M")
    ylabel("Comparacions") 
    pp1.savefig() 
    
    fig, ax = plt.subplots()
    ax = plt.plot(grp['M'],grp['compbo'])
    
    title("M vs comparacions de claus si encerta. Mida diccionari:"+str(di) +" Mida text:"+ str(te))
    xlabel("M")
    ylabel("Comparacions") 
    pp1.savefig() 
    n = n-1
    


pp1.close()
