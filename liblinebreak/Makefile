# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 11:00:32 thomasklausner Exp $
#

DISTNAME=	liblinebreak-0.0.20080420
CATEGORIES=	textproc
MASTER_SITES=	# manually created CVS checkout

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vimgadgets.cvs.sourceforge.net/vimgadgets/common/tools/linebreak/
COMMENT=	Library for line breaking in a Unicode sequence

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/common/tools/linebreak

MAKE_ENV+=	CFG=release PREFIX=${PREFIX}

INSTALLATION_DIRS=	include lib share/doc/liblinebreak

do-install:
	cd ${WRKSRC}/ReleaseDir && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			liblinebreak.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/linebreak.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/linebreakdef.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/liblinebreak

.include "../../mk/bsd.pkg.mk"
