
BIN     = muscle

# Keep this in sync with src/mk
OBJS=   aligngivenpath.o aligngivenpathsw.o aligntwomsas.o aligntwoprofs.o aln.o alpha.o anchors.o bittraceback.o blosum62.o blosumla.o clust.o cluster.o clwwt.o color.o cons.o diaglist.o diffobjscore.o diffpaths.o difftrees.o difftreese.o distcalc.o distfunc.o distpwkimura.o domuscle.o dosp.o dpreglist.o drawtree.o edgelist.o enumopts.o enumtostr.o estring.o fasta.o fasta2.o fastclust.o fastdist.o fastdistjones.o fastdistkbit.o fastdistkmer.o fastdistmafft.o fastdistnuc.o fastscorepath2.o finddiags.o finddiagsn.o glbalign.o glbalign352.o glbaligndiag.o glbalignle.o glbalignsimple.o glbalignsp.o glbalignspn.o glbalignss.o glbalndimer.o globals.o globalslinux.o globalsosx.o globalsother.o globalswin32.o gonnet.o henikoffweight.o henikoffweightpb.o html.o hydro.o intmath.o local.o main.o makerootmsa.o makerootmsab.o maketree.o mhack.o mpam200.o msa.o msa2.o msadistkimura.o msf.o muscle.o muscleout.o nucmx.o nwdasimple.o nwdasimple2.o nwdasmall.o nwrec.o nwsmall.o objscore.o objscore2.o objscoreda.o onexception.o options.o outweights.o pam200mafft.o params.o phy.o phy2.o phy3.o phy4.o phyfromclust.o phyfromfile.o physeq.o phytofile.o posgap.o ppscore.o profdb.o profile.o profilefrommsa.o progalign.o progress.o progressivealign.o pwpath.o readmx.o realigndiffs.o realigndiffse.o refine.o refinehoriz.o refinesubfams.o refinetree.o refinetreee.o refinevert.o refinew.o savebest.o scoredist.o scoregaps.o scorehistory.o scorepp.o seq.o seqvect.o setblosumweights.o setgscweights.o setnewhandler.o spfast.o sptest.o stabilize.o subfam.o subfams.o sw.o termgaps.o textfile.o threewaywt.o tomhydro.o traceback.o tracebackopt.o tracebacksw.o treefrommsa.o typetostr.o upgma2.o usage.o validateids.o vtml2.o writescorefile.o

CC      ?= cc
CXX     ?= c++
LD      ?= c++

.PHONY: all

all: ${BIN}

${BIN}: ${OBJS}
	${CXX} -o ${BIN} ${OBJS}

aligngivenpath.o: aligngivenpath.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h pwpath.h profile.h
	${CXX} -c ${CXXFLAGS} aligngivenpath.cpp

aligngivenpathsw.o: aligngivenpathsw.cpp muscle.h types.h enums.h \
 intmath.h alpha.h params.h msa.h pwpath.h profile.h
	${CXX} -c ${CXXFLAGS} aligngivenpathsw.cpp

aligntwomsas.o: aligntwomsas.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h profile.h pwpath.h textfile.h timing.h
	${CXX} -c ${CXXFLAGS} aligntwomsas.cpp

aligntwoprofs.o: aligntwoprofs.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} aligntwoprofs.cpp

aln.o: aln.cpp muscle.h types.h enums.h intmath.h alpha.h params.h msa.h \
 textfile.h
	${CXX} -c ${CXXFLAGS} aln.cpp

alpha.o: alpha.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} alpha.cpp

anchors.o: anchors.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h objscore.h
	${CXX} -c ${CXXFLAGS} anchors.cpp

bittraceback.o: bittraceback.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h pwpath.h
	${CXX} -c ${CXXFLAGS} bittraceback.cpp

blosum62.o: blosum62.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} blosum62.cpp

blosumla.o: blosumla.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} blosumla.cpp

clust.o: clust.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 clust.h clustset.h
	${CXX} -c ${CXXFLAGS} clust.cpp

cluster.o: cluster.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h cluster.h distfunc.h
	${CXX} -c ${CXXFLAGS} cluster.cpp

clwwt.o: clwwt.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h msa.h
	${CXX} -c ${CXXFLAGS} clwwt.cpp

color.o: color.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h
	${CXX} -c ${CXXFLAGS} color.cpp

cons.o: cons.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h
	${CXX} -c ${CXXFLAGS} cons.cpp

diaglist.o: diaglist.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h diaglist.h pwpath.h
	${CXX} -c ${CXXFLAGS} diaglist.cpp

diffobjscore.o: diffobjscore.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h objscore.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} diffobjscore.cpp

diffpaths.o: diffpaths.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h
	${CXX} -c ${CXXFLAGS} diffpaths.cpp

difftrees.o: difftrees.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h
	${CXX} -c ${CXXFLAGS} difftrees.cpp

difftreese.o: difftreese.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h
	${CXX} -c ${CXXFLAGS} difftreese.cpp

distcalc.o: distcalc.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h distfunc.h distcalc.h msa.h
	${CXX} -c ${CXXFLAGS} distcalc.cpp

distfunc.o: distfunc.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h distfunc.h
	${CXX} -c ${CXXFLAGS} distfunc.cpp

distpwkimura.o: distpwkimura.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h distfunc.h msa.h seqvect.h seq.h pwpath.h
	${CXX} -c ${CXXFLAGS} distpwkimura.cpp

domuscle.o: domuscle.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h textfile.h seqvect.h seq.h distfunc.h msa.h tree.h profile.h \
 pwpath.h timing.h
	${CXX} -c ${CXXFLAGS} domuscle.cpp

dosp.o: dosp.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 textfile.h msa.h objscore.h tree.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} dosp.cpp

dpreglist.o: dpreglist.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h dpreglist.h diaglist.h
	${CXX} -c ${CXXFLAGS} dpreglist.cpp

drawtree.o: drawtree.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h
	${CXX} -c ${CXXFLAGS} drawtree.cpp

edgelist.o: edgelist.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h edgelist.h
	${CXX} -c ${CXXFLAGS} edgelist.cpp

enumopts.o: enumopts.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h enumopts.h
	${CXX} -c ${CXXFLAGS} enumopts.cpp

enumtostr.o: enumtostr.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} enumtostr.cpp

estring.o: estring.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h estring.h seq.h msa.h
	${CXX} -c ${CXXFLAGS} estring.cpp

fasta2.o: fasta2.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} fasta2.cpp

fasta.o: fasta.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h textfile.h
	${CXX} -c ${CXXFLAGS} fasta.cpp

fastclust.o: fastclust.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h seqvect.h seq.h distfunc.h clust.h clustsetdf.h clustset.h \
 msa.h tree.h distcalc.h
	${CXX} -c ${CXXFLAGS} fastclust.cpp

fastdist.o: fastdist.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h distfunc.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} fastdist.cpp

fastdistjones.o: fastdistjones.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h distfunc.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} fastdistjones.cpp

fastdistkbit.o: fastdistkbit.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h distfunc.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} fastdistkbit.cpp

fastdistkmer.o: fastdistkmer.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h seqvect.h seq.h distfunc.h
	${CXX} -c ${CXXFLAGS} fastdistkmer.cpp

fastdistmafft.o: fastdistmafft.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h distfunc.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} fastdistmafft.cpp

fastdistnuc.o: fastdistnuc.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h distfunc.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} fastdistnuc.cpp

fastscorepath2.o: fastscorepath2.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} fastscorepath2.cpp

finddiags.o: finddiags.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h diaglist.h
	${CXX} -c ${CXXFLAGS} finddiags.cpp

finddiagsn.o: finddiagsn.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h diaglist.h
	${CXX} -c ${CXXFLAGS} finddiagsn.cpp

glbalign352.o: glbalign352.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h timing.h textfile.h msa.h profile.h
	${CXX} -c ${CXXFLAGS} glbalign352.cpp

glbalign.o: glbalign.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h timing.h textfile.h msa.h profile.h
	${CXX} -c ${CXXFLAGS} glbalign.cpp

glbaligndiag.o: glbaligndiag.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h dpreglist.h diaglist.h pwpath.h profile.h msa.h \
 timing.h
	${CXX} -c ${CXXFLAGS} glbaligndiag.cpp

glbalignla.o: glbalignla.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} glbalignla.cpp

glbalignle.o: glbalignle.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} glbalignle.cpp

glbalignns.o: glbalignns.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} glbalignns.cpp

glbalignsimple.o: glbalignsimple.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h pwpath.h profile.h msa.h
	${CXX} -c ${CXXFLAGS} glbalignsimple.cpp

glbalignsp.o: glbalignsp.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} glbalignsp.cpp

glbalignspn.o: glbalignspn.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} glbalignspn.cpp

glbalignss.o: glbalignss.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h seq.h
	${CXX} -c ${CXXFLAGS} glbalignss.cpp

glbalndimer.o: glbalndimer.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h profile.h msa.h gapscoredimer.h
	${CXX} -c ${CXXFLAGS} glbalndimer.cpp

globals.o: globals.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} globals.cpp

globalslinux.o: globalslinux.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h
	${CXX} -c ${CXXFLAGS} globalslinux.cpp

globalsosx.o: globalsosx.cpp
	${CXX} -c ${CXXFLAGS} globalsosx.cpp

globalsother.o: globalsother.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h
	${CXX} -c ${CXXFLAGS} globalsother.cpp

globalswin32.o: globalswin32.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h
	${CXX} -c ${CXXFLAGS} globalswin32.cpp

gonnet.o: gonnet.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 gonnet.h
	${CXX} -c ${CXXFLAGS} gonnet.cpp

gotowt.o: gotowt.cpp
	${CXX} -c ${CXXFLAGS} gotowt.cpp

henikoffweight.o: henikoffweight.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h
	${CXX} -c ${CXXFLAGS} henikoffweight.cpp

henikoffweightpb.o: henikoffweightpb.cpp muscle.h types.h enums.h \
 intmath.h alpha.h params.h msa.h
	${CXX} -c ${CXXFLAGS} henikoffweightpb.cpp

html.o: html.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h textfile.h
	${CXX} -c ${CXXFLAGS} html.cpp

hydro.o: hydro.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} hydro.cpp

intmath.o: intmath.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} intmath.cpp

local.o: local.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 textfile.h msa.h profile.h pwpath.h tree.h
	${CXX} -c ${CXXFLAGS} local.cpp

main.o: main.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 svnversion.h
	${CXX} -c ${CXXFLAGS} main.cpp

makerootmsab.o: makerootmsab.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h tree.h profile.h msa.h pwpath.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} makerootmsab.cpp

makerootmsa.o: makerootmsa.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h seqvect.h seq.h profile.h msa.h pwpath.h estring.h
	${CXX} -c ${CXXFLAGS} makerootmsa.cpp

maketree.o: maketree.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h textfile.h tree.h
	${CXX} -c ${CXXFLAGS} maketree.cpp

mhack.o: mhack.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 seqvect.h seq.h msa.h
	${CXX} -c ${CXXFLAGS} mhack.cpp

mpam200.o: mpam200.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} mpam200.cpp

msa2.o: msa2.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h seqvect.h seq.h profile.h pwpath.h tree.h
	${CXX} -c ${CXXFLAGS} msa2.cpp

msa.o: msa.cpp muscle.h types.h enums.h intmath.h alpha.h params.h msa.h \
 textfile.h seq.h
	${CXX} -c ${CXXFLAGS} msa.cpp

msadistkimura.o: msadistkimura.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h
	${CXX} -c ${CXXFLAGS} msadistkimura.cpp

msf.o: msf.cpp muscle.h types.h enums.h intmath.h alpha.h params.h msa.h \
 textfile.h
	${CXX} -c ${CXXFLAGS} msf.cpp

muscle.o: muscle.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h seqvect.h seq.h tree.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} muscle.cpp

muscleout.o: muscleout.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h textfile.h
	${CXX} -c ${CXXFLAGS} muscleout.cpp

nucmx.o: nucmx.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} nucmx.cpp

nwdasimple2.o: nwdasimple2.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h profile.h msa.h
	${CXX} -c ${CXXFLAGS} nwdasimple2.cpp

nwdasimple.o: nwdasimple.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h profile.h msa.h
	${CXX} -c ${CXXFLAGS} nwdasimple.cpp

nwdasmall.o: nwdasmall.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h profile.h msa.h
	${CXX} -c ${CXXFLAGS} nwdasmall.cpp

nwrec.o: nwrec.cpp
	${CXX} -c ${CXXFLAGS} nwrec.cpp

nwsmall.o: nwsmall.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h pwpath.h profile.h msa.h
	${CXX} -c ${CXXFLAGS} nwsmall.cpp

objscore2.o: objscore2.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h profile.h pwpath.h objscore.h
	${CXX} -c ${CXXFLAGS} objscore2.cpp

objscore.o: objscore.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h objscore.h profile.h pwpath.h timing.h
	${CXX} -c ${CXXFLAGS} objscore.cpp

objscoreda.o: objscoreda.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h profile.h pwpath.h objscore.h
	${CXX} -c ${CXXFLAGS} objscoreda.cpp

onexception.o: onexception.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} onexception.cpp

options.o: options.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} options.cpp

outweights.o: outweights.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h
	${CXX} -c ${CXXFLAGS} outweights.cpp

pam200mafft.o: pam200mafft.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} pam200mafft.cpp

params.o: params.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 objscore.h profile.h msa.h pwpath.h enumopts.h
	${CXX} -c ${CXXFLAGS} params.cpp

phy2.o: phy2.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h
	${CXX} -c ${CXXFLAGS} phy2.cpp

phy3.o: phy3.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h edgelist.h
	${CXX} -c ${CXXFLAGS} phy3.cpp

phy4.o: phy4.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h
	${CXX} -c ${CXXFLAGS} phy4.cpp

phy.o: phy.cpp muscle.h types.h enums.h intmath.h alpha.h params.h tree.h
	${CXX} -c ${CXXFLAGS} phy.cpp

phyfromclust.o: phyfromclust.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h tree.h clust.h
	${CXX} -c ${CXXFLAGS} phyfromclust.cpp

phyfromfile.o: phyfromfile.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h textfile.h
	${CXX} -c ${CXXFLAGS} phyfromfile.cpp

physeq.o: physeq.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 msa.h textfile.h
	${CXX} -c ${CXXFLAGS} physeq.cpp

phytofile.o: phytofile.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h textfile.h
	${CXX} -c ${CXXFLAGS} phytofile.cpp

posgap.o: posgap.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} posgap.cpp

ppscore.o: ppscore.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h textfile.h msa.h tree.h profile.h pwpath.h objscore.h
	${CXX} -c ${CXXFLAGS} ppscore.cpp

profdb.o: profdb.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 textfile.h seqvect.h seq.h distfunc.h msa.h tree.h clust.h profile.h \
 pwpath.h clustsetmsa.h clustset.h msadist.h
	${CXX} -c ${CXXFLAGS} profdb.cpp

profile.o: profile.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h textfile.h msa.h tree.h profile.h pwpath.h objscore.h
	${CXX} -c ${CXXFLAGS} profile.cpp

profilefrommsa.o: profilefrommsa.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} profilefrommsa.cpp

progalign.o: progalign.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h seqvect.h seq.h profile.h msa.h pwpath.h distfunc.h \
 textfile.h estring.h
	${CXX} -c ${CXXFLAGS} progalign.cpp

progress.o: progress.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} progress.cpp

progressivealign.o: progressivealign.cpp muscle.h types.h enums.h \
 intmath.h alpha.h params.h tree.h seqvect.h seq.h profile.h msa.h \
 pwpath.h distfunc.h
	${CXX} -c ${CXXFLAGS} progressivealign.cpp

pwpath.o: pwpath.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 pwpath.h seq.h textfile.h msa.h
	${CXX} -c ${CXXFLAGS} pwpath.cpp

readmx.o: readmx.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 textfile.h
	${CXX} -c ${CXXFLAGS} readmx.cpp

realigndiffs.o: realigndiffs.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h tree.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} realigndiffs.cpp

realigndiffse.o: realigndiffse.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h tree.h profile.h pwpath.h seqvect.h seq.h \
 estring.h
	${CXX} -c ${CXXFLAGS} realigndiffse.cpp

refine.o: refine.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 textfile.h seqvect.h seq.h distfunc.h msa.h tree.h clust.h profile.h \
 pwpath.h clustsetmsa.h clustset.h msadist.h
	${CXX} -c ${CXXFLAGS} refine.cpp

refinehoriz.o: refinehoriz.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h msa.h pwpath.h profile.h scorehistory.h objscore.h
	${CXX} -c ${CXXFLAGS} refinehoriz.cpp

refinesubfams.o: refinesubfams.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h tree.h clust.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} refinesubfams.cpp

refinetree.o: refinetree.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h tree.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} refinetree.cpp

refinetreee.o: refinetreee.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h tree.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} refinetreee.cpp

refinevert.o: refinevert.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h seqvect.h seq.h clust.h tree.h
	${CXX} -c ${CXXFLAGS} refinevert.cpp

refinew.o: refinew.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h seqvect.h seq.h textfile.h
	${CXX} -c ${CXXFLAGS} refinew.cpp

savebest.o: savebest.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h textfile.h
	${CXX} -c ${CXXFLAGS} savebest.cpp

scoredist.o: scoredist.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h distfunc.h seqvect.h seq.h pwpath.h
	${CXX} -c ${CXXFLAGS} scoredist.cpp

scoregaps.o: scoregaps.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h objscore.h
	${CXX} -c ${CXXFLAGS} scoregaps.cpp

scorehistory.o: scorehistory.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h scorehistory.h
	${CXX} -c ${CXXFLAGS} scorehistory.cpp

scoremx.o: scoremx.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} scoremx.cpp

scorepp.o: scorepp.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} scorepp.cpp

seq.o: seq.cpp muscle.h types.h enums.h intmath.h alpha.h params.h seq.h \
 textfile.h msa.h
	${CXX} -c ${CXXFLAGS} seq.cpp

seqvect.o: seqvect.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h seqvect.h seq.h textfile.h msa.h
	${CXX} -c ${CXXFLAGS} seqvect.cpp

setblosumweights.o: setblosumweights.cpp muscle.h types.h enums.h \
 intmath.h alpha.h params.h msa.h cluster.h distfunc.h
	${CXX} -c ${CXXFLAGS} setblosumweights.cpp

setgscweights.o: setgscweights.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h cluster.h distfunc.h
	${CXX} -c ${CXXFLAGS} setgscweights.cpp

setnewhandler.o: setnewhandler.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h
	${CXX} -c ${CXXFLAGS} setnewhandler.cpp

spfast.o: spfast.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} spfast.cpp

sptest.o: sptest.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 objscore.h msa.h textfile.h pwpath.h
	${CXX} -c ${CXXFLAGS} sptest.cpp

stabilize.o: stabilize.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h
	${CXX} -c ${CXXFLAGS} stabilize.cpp

subfam.o: subfam.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h textfile.h msa.h seqvect.h seq.h profile.h pwpath.h
	${CXX} -c ${CXXFLAGS} subfam.cpp

subfams.o: subfams.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h distfunc.h
	${CXX} -c ${CXXFLAGS} subfams.cpp

sw.o: sw.cpp muscle.h types.h enums.h intmath.h alpha.h params.h pwpath.h \
 profile.h msa.h
	${CXX} -c ${CXXFLAGS} sw.cpp

termgaps.o: termgaps.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} termgaps.cpp

textfile.o: textfile.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h textfile.h
	${CXX} -c ${CXXFLAGS} textfile.cpp

threewaywt.o: threewaywt.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h tree.h
	${CXX} -c ${CXXFLAGS} threewaywt.cpp

tomhydro.o: tomhydro.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} tomhydro.cpp

traceback.o: traceback.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} traceback.cpp

tracebackopt.o: tracebackopt.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h pwpath.h
	${CXX} -c ${CXXFLAGS} tracebackopt.cpp

tracebacksw.o: tracebacksw.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h profile.h msa.h pwpath.h
	${CXX} -c ${CXXFLAGS} tracebacksw.cpp

treefrommsa.o: treefrommsa.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h tree.h clust.h clustsetmsa.h clustset.h msadist.h \
 distcalc.h
	${CXX} -c ${CXXFLAGS} treefrommsa.cpp

typetostr.o: typetostr.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h
	${CXX} -c ${CXXFLAGS} typetostr.cpp

upgma2.o: upgma2.cpp muscle.h types.h enums.h intmath.h alpha.h params.h \
 tree.h distcalc.h
	${CXX} -c ${CXXFLAGS} upgma2.cpp

usage.o: usage.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} usage.cpp

validateids.o: validateids.cpp muscle.h types.h enums.h intmath.h alpha.h \
 params.h msa.h tree.h seqvect.h seq.h
	${CXX} -c ${CXXFLAGS} validateids.cpp

vtml2.o: vtml2.cpp muscle.h types.h enums.h intmath.h alpha.h params.h
	${CXX} -c ${CXXFLAGS} vtml2.cpp

writescorefile.o: writescorefile.cpp muscle.h types.h enums.h intmath.h \
 alpha.h params.h msa.h
	${CXX} -c ${CXXFLAGS} writescorefile.cpp
