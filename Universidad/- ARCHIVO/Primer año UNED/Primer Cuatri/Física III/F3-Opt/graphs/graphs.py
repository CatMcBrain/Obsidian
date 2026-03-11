# Set ROOT
from pathlib import Path
ROOT = Path(__file__).resolve().parent

import numpy as np
import pandas as pd
import matplotlib as mpl
from matplotlib import pyplot as plt
from matplotlib import style
import seaborn as sb

# Graph style
sb.set_theme(style="white")

mpl.rcParams.update({
    # Color cycle (lines + scatter fill)
    "axes.prop_cycle": mpl.cycler(color=["#B21807"]),

    # Lines and markers
    "lines.linewidth": 0.9,       # thin trend line
    "lines.markersize": 6,        # default marker size
    "scatter.edgecolors": "black",  # black edges for scatter points

    # Axes
    "axes.facecolor": "white",
    "axes.edgecolor": "black",
    "axes.linewidth": 1.0,
    "axes.labelsize": 12,
    "axes.labelweight": "normal",

    # Ticks (Origin-like: inward)
    "xtick.direction": "in",
    "ytick.direction": "in",
    "xtick.major.size": 5,
    "ytick.major.size": 5,
    "xtick.minor.size": 3,
    "ytick.minor.size": 3,
    "xtick.major.width": 1.0,
    "ytick.major.width": 1.0,
    "xtick.minor.width": 0.8,
    "ytick.minor.width": 0.8,

    # Fonts
    "font.family": "serif",
    "font.serif": ["Times New Roman", "Palatino", "Computer Modern"],
    "font.size": 11,

    # Figure
    "figure.figsize": (6, 4),
    "figure.dpi": 100,
    "savefig.dpi": 300,

    # Legend
    "legend.frameon": False,

    # Grid (optional subtle grid)
    "grid.color": "0.9",
    "grid.linestyle": ":",
    "grid.linewidth": 0.5
})


plt.minorticks_on()
plt.grid(True, which="major", linestyle=":", linewidth=0.5, alpha=0.6)
plt.grid(True, which="minor", linestyle=":", linewidth=0.3, alpha=0.3)


# Import data
data= pd.read_csv(ROOT/'data.csv', sep=",")
data = data[data["z"] >= 0]

# Plot

sb.regplot(
	data=data,
	x='d (Mpc)',
	y='v (km/s)',
	scatter=True,
	ci=None,
	scatter_kws={
        "edgecolor": "black",  
        "facecolor": "black",  
        "s": 30,  # marker size
		"alpha": 1.0,
		"zorder": 3
    },
    line_kws={
        "color": "#782118",  # dark red line
        "linewidth": 0.9,
		"zorder":2
    }
)

# Slope
x= data['d (Mpc)'].to_numpy()
y= data['v (km/s)'].to_numpy()
m, b= np.polyfit(x,y,1) # b es intercepto

plt.text(
	0.05,0.95,
	f"m = {m:.5} (km s-1 Mpc-1)", # Show m with 2 decimals ^1
	transform=plt.gca().transAxes, # Evita que se mueva con los límites del gráfico
	fontsize=10,
	verticalalignment='top',
	bbox=dict(boxstyle='square',facecolor='white',edgecolor='black')
)

#^1 used an f string, which allows me to input variable values inside a string when i place them inside curly brackets

plt.savefig(ROOT/"graph.png", dpi=300, bbox_inches="tight")
plt.show()