# $NetBSD: Makefile,v 1.1 2012/12/17 22:15:49 othyro Exp $
#

DISTNAME=	snotes-1.1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=s-notes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://s-notes.sourceforge.net/
COMMENT=	Little note windows on your desktop
LICENSE=	gnu-gpl-v2 AND qpl-v1.0

WRKSRC=		${WRKDIR}/snotes
USE_LANGUAGES=	c++
QMAKE=		${QTDIR}/bin/qmake

INSTALLATION_DIRS+=	bin

pre-configure:
		cd ${WRKSRC} && \
			${SETENV} ${CONFIGURE_ENV} ${QMAKE} -project && \
				${QMAKE} -nocache

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
