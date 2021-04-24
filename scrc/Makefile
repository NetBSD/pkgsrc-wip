# $NetBSD: Makefile,v 1.4 2013/02/13 12:21:15 makoto Exp $

DISTNAME=		scrc-2.1
CATEGORIES=		cad
MASTER_SITES=		http://www.cecs.uci.edu/~specc/ftp/reference/

MAINTAINER=		makoto@ki.nu
HOMEPAGE=		http://www.cecs.uci.edu/~specc/reference/
COMMENT=		SpecC Reference Compiler
LICENSE=		modified-bsd

USE_LANGUAGES+=		c++
USE_LANGUAGES+=		c

# mkdir etc is hardcoded, not so easy to make it.

USE_TOOLS+=		gmake gtar

DEPENDS+=		bison>=1.35:../../devel/bison
DEPENDS+=		unix2dos-[0-9]*:../../converters/unix2dos

#ONLY_FOR_PLATFORM=	NetBSD-*-i386
#ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

PKG_GROUPS=		specc
PKG_USERS=		specc:specc
PKG_GECOS.smmsp=	SpecC Language admin

PLIST_SUBST+=		SCRCPREF=${DISTNAME}

CHECK_SHLIBS=		NO
#SPECIAL_PERMS=

.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC} && ${GMAKE} all

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} ${GMAKE} install

# post-install:
#	(cd ${WRKSRC}; ${GMAKE} install)
#	echo test

pre-configure:
	${ECHO}	  \*\*\* pre-configure is running
	(cd ${WRKSRC} ; \
	for i in  Makefile.macros src/Compiler/Makefile; do \
	mv $$i $$i.bak ;\
	sed -e 's|@@SPECC@@|${WRKSRC}|g' \
	    -e 's|@@PREFIX@@|${PREFIX}|g' \
	    -e 's|@@PKGNAME@@|${PKGNAME}|g' \
		 ${WRKSRC}/$${i}.bak \
	       > ${WRKSRC}/$${i}; \
	done; )

.include "../../mk/bsd.pkg.mk"
