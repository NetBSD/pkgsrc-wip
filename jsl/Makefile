# $NetBSD: Makefile,v 1.1.1.1 2010/06/28 13:47:42 hfath Exp $
#

DISTNAME=	jsl-0.3.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	http://www.javascriptlint.com/download/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.javascriptlint.com/
COMMENT=	Standalone JavaScript lint
LICENSE=	mpl-1.1

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR}

DOCDIR=		share/doc/html/jsl
EGDIR=		share/examples/jsl
EGCONFIGFILE=	jsl.config.sample

USE_TOOLS+=	gmake
MAKE_FILE=	${WRKSRC}/Makefile.ref
WRKSRC=		${WRKDIR}/jsl-0.3.0/src

pre-install:
	(cd ${WRKSRC} && pkgsrc.objdir/jsl -help:conf > ${EGCONFIGFILE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgsrc.objdir/jsl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.html ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/${EGCONFIGFILE} ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
