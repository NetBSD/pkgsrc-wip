# $NetBSD: Makefile,v 1.8 2005/03/24 21:13:28 thomasklausner Exp $

DISTNAME=	frontpage-5.0.2.2623
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.microsoft.com/products/frontpage/ \
		ftp://www.westbend.net/Mirrors/ftp.microsoft.com/Products/frontpage/
DISTFILES=	${FRONTPAGE}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.microsoft.com/frontpage
COMMENT=	Microsoft Frontpage 2002 Server Extensions

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/frontpage
EXTRACT_SFX=	.Z
USE_PKGINSTALL=	YES

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-alpha
#			Linux-*-i386 \
#			SunOS-*-sparc64 SunOS-*-x86

.if	${OPSYS} == "NetBSD"
DEPENDS+=	ap-frontpage>=1.6.2:../../wip/ap-frontpage
. if	${MACHINE_ARCH} == "i386"
FRONTPAGE=	fp${FP_VER:S/.//}.bsdi.tar.Z
. elif	${MACHINE_ARCH} == "alpha"
FRONTPAGE=	fp${FP_VER:S/.//}.alpha.tar.Z
RUN_DEPENDS+=	osf1-lib:../../emulators/osf1-lib
. elif	${MACHINE_ARCH} == "sparc64"
FRONTPAGE=	fp${FP_VER:S/.//}.solaris.tar.Z
. elif	${MACHINE_ARCH} == "sparc"
FRONTPAGE=	fp${FP_VER:S/.//}.solaris.tar.Z
. endif
# .elif	${OPSYS} == "SunOS"
# . if	${MACHINE_ARCH} == "i386"
# FRONTPAGE=	fp${FP_VER:S/.//}.solarisx86.tar.Z
# . elif	${MACHINE_ARCH} == "sparc64"
# FRONTPAGE=	fp${FP_VER:S/.//}.solaris.tar.Z
# . elif	${MACHINE_ARCH} == "sparc"
# FRONTPAGE=	fp${FP_VER:S/.//}.solaris.tar.Z
# . endif
.endif

FP_VER=		5.0
#FP_VER=		${PORTVERSION:C/\..*//}

BUILD_DEFS+=	FP_DIR
BUILD_DEFS+=	FPOWN FPGRP

EXTRACT_ONLY=	${FRONTPAGE}

FP_DIR=		frontpage/version${FP_VER}
FPINSTALL=	${FP_DIR}/fp_install.sh
README=		${FP_DIR}/readme.htm
FPCSS=		${FP_DIR}/admin/1033/webadmin.css
FPOWN?=		${BINOWN}
FPGRP?=		${BINGRP}

MOD_FPDOCDIR=	share/httpd/htdocs/manual/frontpage

PLIST_SUBST+=	FP_VER=${FP_VER}

METALOG=	${WRKDIR}/.METALOG

do-build:
	@${MV} ${WRKDIR}/${FPCSS} ${WRKDIR}/${FPCSS}.orig
	@${SED} -e 's:IMAGESDIR:../images/:g' \
		${WRKDIR}/${FPCSS}.orig > ${WRKDIR}/${FPCSS}
	@${MV} ${WRKDIR}/${FPINSTALL} ${WRKDIR}/${FPINSTALL}.orig
	@${SED} -e 's:PREFIX:${PREFIX}:g' \
		${WRKDIR}/${FPINSTALL}.orig > ${WRKDIR}/${FPINSTALL}
	@${MKDIR} ${WRKDIR}/${MOD_FPDOCDIR}
	@${CP} ${WRKDIR}/${README} ${WRKDIR}/${MOD_FPDOCDIR}/index.html

metalog: ${METALOG}

#	some rather ugly scripting to generate a METALOG file
#	to be fed to pax. On the other hand, we're kinda clever 
#	to build the metalog file from the PLIST :-)
#
#	note, the file ownerships have to match those used
#	in ap-frontpage, which sets the file owner/group to
#		BINOWN/BINGRP (FP from MS expects those to be bin/bin)
#
pre-install ${METALOG}: plist
	@cd ${WRKDIR}; \
	(${ECHO} "."; \
	 dn=${MOD_FPDOCDIR} ; \
	 while [ -n $$dn -a "$$dn" != "." ] ; do \
	    ${ECHO} $$dn; \
	    dn=`dirname $$dn` ; \
	 done ;\
	 ${SED} -e 's/^@dirrm //' -e '/^@.*/d' ${PLIST} )| \
	while read fn; do \
	    if [ "$$fn" != "." ] ; then \
		fn="./$$fn"; \
	    fi ; \
	    if [ -f $$fn ] ; then \
		type="file"; \
		case $$fn in \
		    *.exe|*.sh)	mode=0555;; \
		    *)		mode=0444;; \
		esac ;\
	    elif [ -d $$fn ] ; then \
		type="dir" ; \
		mode=0755; \
	    fi; \
	    ${ECHO} "$$fn type=$$type mode=$$mode uname=${FPOWN} gname=${FPGRP}";\
	done | ${SORT} >${METALOG}

do-install:
	@cd ${WRKDIR} && ${PAX} -O -ppo -rw -d -M ${PREFIX} < ${METALOG}

.include "../../mk/bsd.pkg.mk"
