#!@RCD_SCRIPTS_SHELL@
#
#  PPower4 shell script file                 last update: 29 Aug 2002
#
#  minimal usage:
#	ppower4 input.pdf output.pdf
#
#  Note: input.pdf and output.pdf must be different.
#
#  It is assumed that you have at least Java 1.2.x installed
#  and can call it with the command java. Otherwise specify the
#  path for your Java runtime system.
#
#  Modify this script such that jarfile contains the full path
#  of the pp4p.jar file.
#
#jarfile=/common/Java/lib/ppower4/pp4p.jar
#
#  If you use a web2c distribution, you can place pp4p.jar 
#  e.g. into the directory texmf/java/ppower4, run mktexlsr,
#  comment the assignment above and uncomment the assignment below.
#  Thanks to Reinhard Kotucha for contributing this suggestion.
#
jarfile=`kpsewhich -progname=java -format='other binary files' pp4p.jar`
# 
#
java -jar ${jarfile} "$@"
