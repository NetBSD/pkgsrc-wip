# $NetBSD: Makefile,v 1.2 2012/09/29 17:05:56 asau Exp $
#

DISTNAME=	HiggsBounds-3.8.0
PKGNAME=	higgsbounds-3.8.0
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/higgsbounds/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/higgsbounds/
COMMENT=	Selection of Higgs sector predictions for any particular model
LICENSE=	gnu-gpl-v3

#DEPENDS+=	feynhiggs-[0-9]*:../../wip/feynhiggs

WRKSRC=	${WRKDIR}/${DISTNAME}/HiggsBounds

HAS_CONFIGURE=	yes
USE_TOOLS+=	bash:run gmake
USE_LANGUAGES=	fortran

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	create_store_pathname.bat

MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_FLAGS} -f ${MAKE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/HiggsBounds ${DESTDIR}${PREFIX}/bin


.include "../../mk/bsd.pkg.mk"
