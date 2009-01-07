# $NetBSD: plugs.mk,v 1.1.1.1 2009/01/07 12:33:56 tnn2 Exp $

#PLUGS=			jdk-7-ea-plug-b42-linux-i586-19_dec_2008.jar
#SITES.${PLUGS}=	http://www.java.net/download/openjdk/jdk7/promoted/b42/
#DISTFILES+=		${PLUGS}
#EXTRACT_ONLY+=		${PLUGS}
#MAKE_ENV+=		ALT_BINARY_PLUGS_PATH=${WRKDIR}/openjdk-binary-plugs

# XXX from OpenBSD ports
PLUGS=			jdk-7-icedtea-plugs-1.6a.tar.gz
SITES.${PLUGS}=		http://www.intricatesoftware.com/distfiles/
DISTFILES+=		${PLUGS}
EXTRACT_ONLY+=		${PLUGS}
MAKE_ENV+=		ALT_BINARY_PLUGS_PATH=${WRKDIR}/jdk-7-icedtea-plugs
