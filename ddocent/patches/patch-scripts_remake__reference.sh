$NetBSD$

Ensure $SHELL is set to bash. Use proper names for GNU programs.
--- scripts/remake_reference.sh.orig	2018-06-15 14:35:28 UTC
+++ scripts/remake_reference.sh
@@ -1,16 +1,25 @@
+#!/usr/bin/env bash
+
 export LC_ALL=en_US.UTF-8
+export SHELL=%%PREFIX%%/bin/bash
 
 if [[ -z "$5" ]]; then
 echo "Usage is sh remake_reference.sh K1 K2 similarity% Assembly_Type Number_of_Processors"
 exit 1
 fi
 
-if ! awk --version | fgrep -v GNU &>/dev/null; then
+if ! awk --version | fgrep -q GNU; then
          awk=gawk
-    else
+else
          awk=awk
 fi
 
+if ! sort --version | fgrep -q GNU; then
+	sort=gsort
+else
+	sort=sort
+fi
+
 if find ${PATH//:/ } -maxdepth 1 -name trimmomatic*jar 2> /dev/null| grep -q 'trim' ; then
 	TRIMMOMATIC=$(find ${PATH//:/ } -maxdepth 1 -name trimmomatic*jar 2> /dev/null | head -1)
 	else
@@ -52,7 +61,7 @@ if [ ${NAMES[@]:(-1)}.F.fq.gz -nt ${NAME
 		cat namelist | parallel --no-notice -j $NUMProc "zcat {}.F.fq.gz | mawk '$AWK1' | mawk '$AWK2' > {}.forward"
 		cat namelist | parallel --no-notice -j $NUMProc "zcat {}.R.fq.gz | mawk '$AWK1' | mawk '$AWK2' > {}.reverse"
 		if [ "$ATYPE" = "RPE" ]; then
-			cat namelist | parallel --no-notice -j $NUMProc "paste {}.forward {}.reverse | sort -k1 -S 100M > {}.fr"
+			cat namelist | parallel --no-notice -j $NUMProc "paste {}.forward {}.reverse | $sort -k1 -S 100M > {}.fr"
 			cat namelist | parallel --no-notice -j $NUMProc "cut -f1 {}.fr | uniq -c > {}.f.uniq && cut -f2 {}.fr > {}.r"
 			cat namelist | parallel --no-notice -j $NUMProc "mawk '$AWK4' {}.f.uniq > {}.f.uniq.e" 
 			cat namelist | parallel --no-notice -j $NUMProc "paste -d '-' {}.f.uniq.e {}.r | mawk '$AWK3'| sed 's/-/NNNNNNNNNN/' | sed -e '$SED1' | sed -e '$SED2'> {}.uniq.seqs"
@@ -88,7 +97,7 @@ if [ ${NAMES[@]:(-1)}.F.fq.gz -nt ${NAME
       do
       zcat $i.R.fq.gz | head -2 | tail -1 >> lengths.txt
       done	
-    MaxLen=$(mawk '{ print length() | "sort -rn" }' lengths.txt| head -1)
+    MaxLen=$(mawk '{ print length() | "$sort -rn" }' lengths.txt| head -1)
     LENGTH=$(( $MaxLen / 3))
 		for i in "${NAMES[@]}"
 			do
@@ -110,12 +119,12 @@ if [[ "$ATYPE" == "RPE" || "$ATYPE" == "
   parallel --no-notice -j $NUMProc mawk -v x=$CUTOFF \''$1 >= x'\' ::: *.uniq.seqs | cut -f2 | sed 's/NNNNNNNNNN/-/' >  total.uniqs
   cut -f 1 -d "-" total.uniqs > total.u.F
   cut -f 2 -d "-" total.uniqs > total.u.R
-  paste total.u.F total.u.R | sort -k1 --parallel=$NUMProc -S 2G > total.fr
+  paste total.u.F total.u.R | $sort -k1 --parallel=$NUMProc -S 2G > total.fr
   special_uniq(){
     mawk -v x=$1 '$1 >= x' $2  |cut -f2 | sed -e 's/NNNNNNNNNN/	/g' | cut -f1 | uniq
   }
   export -f special_uniq
-  parallel --no-notice --env special_uniq special_uniq $CUTOFF {} ::: *.uniq.seqs  | sort --parallel=$NUMProc -S 2G | uniq -c > total.f.uniq
+  parallel --no-notice --env special_uniq special_uniq $CUTOFF {} ::: *.uniq.seqs  | $sort --parallel=$NUMProc -S 2G | uniq -c > total.f.uniq
   join -1 2 -2 1 -o 1.1,1.2,2.2 total.f.uniq total.fr | mawk '{print $1 "\t" $2 "NNNNNNNNNN" $3}' | mawk -v x=$CUTOFF2 '$1 >= x' > uniq.k.$CUTOFF.c.$CUTOFF2.seqs
   rm total.uniqs total.u.* total.fr total.f.uniq* 
   
@@ -123,7 +132,7 @@ else
 	parallel --no-notice mawk -v x=$CUTOFF \''$1 >= x'\' ::: *.uniq.seqs | cut -f2 | perl -e 'while (<>) {chomp; $z{$_}++;} while(($k,$v) = each(%z)) {print "$v\t$k\n";}' | mawk -v x=$CUTOFF2 '$1 >= x' > uniq.k.$CUTOFF.c.$CUTOFF2.seqs
 fi
 
-sort -k1 -r -n --parallel=$NUMProc -S 2G uniq.k.$CUTOFF.c.$CUTOFF2.seqs |cut -f2 > totaluniqseq
+$sort -k1 -r -n --parallel=$NUMProc -S 2G uniq.k.$CUTOFF.c.$CUTOFF2.seqs |cut -f2 > totaluniqseq
 mawk '{c= c + 1; print ">dDocent_Contig_" c "\n" $1}' totaluniqseq > uniq.full.fasta
 LENGTH=$(mawk '!/>/' uniq.full.fasta  | mawk '(NR==1||length<shortest){shortest=length} END {print shortest}')
 LENGTH=$(($LENGTH * 3 / 4))
@@ -159,21 +168,21 @@ if [[ "$ATYPE" == "PE" || "$ATYPE" == "R
 		sed -e 's/NNNNNNNNNN/	/g' uniq.fasta | cut -f1 > uniq.F.fasta
 	  	CDHIT=$(python -c "print (max("$simC" - 0.1,0.8))")
 	  	cd-hit-est -i uniq.F.fasta -o xxx -c $CDHIT -T $NUMProc -M 0 -g 1 -d 100 &>cdhit.log
-	  	mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids
+	  	mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | $sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids
 	  	paste sort.contig.cluster.ids totaluniqseq > contig.cluster.totaluniqseq
           
      	else
-        	sed -e 's/NNNNNNNNNN/	/g' totaluniqseq | cut -f1 | sort --parallel=$NUMProc -S 2G| uniq | mawk '{c= c + 1; print ">dDocent_Contig_" c "\n" $1}' > uniq.F.fasta
+        	sed -e 's/NNNNNNNNNN/	/g' totaluniqseq | cut -f1 | $sort --parallel=$NUMProc -S 2G| uniq | mawk '{c= c + 1; print ">dDocent_Contig_" c "\n" $1}' > uniq.F.fasta
 		CDHIT=$(python -c "print (max("$simC" - 0.1,0.8))")
 		cd-hit-est -i uniq.F.fasta -o xxx -c $CDHIT -T $NUMProc -M 0 -g 1 -d 100 &>cdhit.log
-  		mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids
+  		mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | $sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids
   		paste sort.contig.cluster.ids <(mawk '!/>/' uniq.F.fasta) > contig.cluster.Funiq
-  		sed -e 's/NNNNNNNNNN/	/g' totaluniqseq | sort --parallel=$NUMProc -k1 -S 2G | mawk '{print $0 "\t" NR}'  > totaluniqseq.CN
+  		sed -e 's/NNNNNNNNNN/	/g' totaluniqseq | $sort --parallel=$NUMProc -k1 -S 2G | mawk '{print $0 "\t" NR}'  > totaluniqseq.CN
   		join -t $'\t' -1 3 -2 1 contig.cluster.Funiq totaluniqseq.CN -o 2.3,1.2,2.1,2.2 > contig.cluster.totaluniqseq
 	fi	
 	
 	#CD-hit output is converted to rainbow format
-	sort -k2,2 -g contig.cluster.totaluniqseq -S 2G --parallel=$NUMProc | sed -e 's/NNNNNNNNNN/	/g' > rcluster
+	$sort -k2,2 -g contig.cluster.totaluniqseq -S 2G --parallel=$NUMProc | sed -e 's/NNNNNNNNNN/	/g' > rcluster
 	rainbow div -i rcluster -o rbdiv.out -f 0.5 -K 10
         CLUST=(`tail -1 rbdiv.out | cut -f5`)
 	CLUST1=$(( $CLUST / 100 + 1))
@@ -242,9 +251,9 @@ if [[ "$ATYPE" == "HYB" ]];then
 		sed -e 's/NNNNNNNNNN/	/g' uniq.ua.fasta | cut -f1 > uniq.F.ua.fasta
 		CDHIT=$(python -c "print(max("$simC" - 0.1,0.8))")
 		cd-hit-est -i uniq.F.ua.fasta -o xxx -c $CDHIT -T 0 -M 0 -g 1 -d 100 &>cdhit.log
-		mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids.ua
+		mawk '{if ($1 ~ /Cl/) clus = clus + 1; else  print $3 "\t" clus}' xxx.clstr | sed 's/[>dDocent_Contig_,...]//g' | $sort -g -k1 -S 2G --parallel=$NUMProc > sort.contig.cluster.ids.ua
 		paste sort.contig.cluster.ids.ua totaluniqseq.ua > contig.cluster.totaluniqseq.ua
-		sort -k2,2 -g -S 2G --parallel=$NUMProc contig.cluster.totaluniqseq.ua | sed -e 's/NNNNNNNNNN/	/g' > rcluster.ua
+		$sort -k2,2 -g -S 2G --parallel=$NUMProc contig.cluster.totaluniqseq.ua | sed -e 's/NNNNNNNNNN/	/g' > rcluster.ua
 		#CD-hit output is converted to rainbow format
 		rainbow div -i rcluster.ua -o rbdiv.ua.out -f 0.5 -K 10
 		if [ "$ATYPE" == "PE" ]; then
