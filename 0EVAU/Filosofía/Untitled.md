```latex
\documentclass{article}
\usepackage{amsmath, amssymb, graphicx, booktabs, hyperref, xcolor}

\begin{document}

\title{SwiftLaTeX Example}
\author{Obsidian User}
\date{\today}
\maketitle

\section{Mathematics Example}
Here is an equation using the \texttt{amsmath} package:
\begin{equation}
    E = mc^2
\end{equation}

\section{Table Example}
We use the \texttt{booktabs} package for a clean table:

\begin{table}[h]
    \centering
    \begin{tabular}{l c r}
        \toprule
        Name & Age & Score \\
        \midrule
        Alice & 23 & 85 \\
        Bob & 25 & 92 \\
        Charlie & 22 & 88 \\
        \bottomrule
    \end{tabular}
    \caption{Sample Table}
    \label{tab:sample}
\end{table}

\section{Image Example}
Using the \texttt{graphicx} package, we can include an image:

\begin{figure}[h]
    \centering
    \includegraphics[width=0.5\textwidth]{example-image}
    \caption{Example Image}
    \label{fig:example}
\end{figure}

\section{Hyperlink Example}
Using the \texttt{hyperref} package, we can create links:
\href{https://www.example.com}{Click here for more information}.

\end{document}
```


