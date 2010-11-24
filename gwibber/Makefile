# $NetBSD: Makefile,v 1.1.1.1 2010/11/24 09:32:26 ryo-on Exp $
#

DISTNAME=	gwibber_2.91.0.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/g/gwibber/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://gwibber.com/
COMMENT=	Open source microblogging client
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/gwibber-2.91.0
USE_LANGUAGES=	# none
USE_TOOLS+=	intltool

DEPENDS+=	${PYPKGPREFIX}-dbus>=0.80.2:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.10.4:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gnome2>=2.18.0:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.6:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-notify>=0.1.1:../../sysutils/py-notify
DEPENDS+=	${PYPKGPREFIX}-webkit>=1.0.1:../../wip/py-webkit
DEPENDS+=	${PYPKGPREFIX}-simplejson>=1.9.1:../../converters/py-simplejson
#DEPENDS+=	${PYPKGPREFIX}->=:../../
DEPENDS+=	${PYPKGPREFIX}-distutils-extra-[0-9]*:../../wip/py-distutils-extra
DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-xdg>=0.15:../../devel/py-xdg
#DEPENDS+=	${PYPKGPREFIX}->=:../../
DEPENDS+=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	setup.cfg
SUBST_SED.prefix=	-e 's,/usr,${PREFIX},'

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
