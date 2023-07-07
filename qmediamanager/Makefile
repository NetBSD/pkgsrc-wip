# $NetBSD$

DISTNAME=	qmediamanager-0.1.0.18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	c2e2c6377b9de8bd8f05baf2e596d26c5a294804

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/qmediamanager
COMMENT=	GUI tool for managing removable media
LICENSE=	2-clause-bsd

DEPENDS=	npmount>0:../../wip/npmount
DEPENDS+=	devpub-mount>0:../../wip/devpub-mount
DEPENDS+=	auto-admin>=0.7.17.8:../../sysutils/auto-admin
DEPENDS+=	rxvt-unicode>0:../../x11/rxvt-unicode
# Maybe use qt5/6 options.  See net/wireshark.
DEPENDS+=	qt6-qttools>0:../../devel/qt6-qttools

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'
SUBST_FILES.prefix=	misc.h

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin man/man1

do-configure:
	(cd ${WRKSRC} && ${PREFIX}/qt6/bin/qmake)

do-install:
	${INSTALL} -c ${WRKSRC}/qmediamanager ${DESTDIR}${PREFIX}/bin
	${INSTALL} -c ${WRKSRC}/Man/qmediamanager.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libxtend/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
