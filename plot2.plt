set nokey
set lmargin 10  # 左マージン
set rmargin 5   # 右マージン
set tmargin 1.4   # 上マージン
set bmargin 1.4   # 下マージン
set mapping spherical
set xrange [-1.5:1.5]
set yrange [-1.5:1.5]
set zrange [-1.5:1.5]
set grid
set view equal xyz
lines = "0 6 12 18 24 30 36 42 48 54 60 66 -1"
colors = "red blue black green brown red blue green brown red blue black green brown "
splot for [i=1:12] 'out-pentax3.txt' every ::word(lines, i)::(word(lines, i+1)-1) with lines lt 2 lc rgb word(colors, i)
if (exist("FRAG") == 0) \
     pause -1 "Click OK to make EPS file";\
     set out "PSK.eps";\
     set term post eps color enhanced "Arial,25" size 5in,6in;;\
     FRAG = 1; reread

undefine FRAG
set out
set term pop