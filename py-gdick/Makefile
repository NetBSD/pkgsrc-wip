# $NetBSD: Makefile,v 1.5 2003/11/18 04:44:33 minskim Exp $

DISTNAME=	gdick-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gdick/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://gdick.sourceforge.net/
COMMENT=	English-Korean Dictionary Client for GNOME2

DEPENDS+=	${PYPKGPREFIX}-cjkcodecs-[0-9]*:../../wip/py-cjkcodecs

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

NO_CONFIGURE=	yes

post-patch:
.for f in gdick gdick_applet lib/gdick/gdick.py lib/gdick/YahooDict.py \
		GNOME_GDick.server
	cd ${WRKSRC}; ${MV} $f $f.orig; \
	${SED} -e \
		's,/usr/,${LOCALBASE}/,g' \
		$f.orig > $f
.endfor

.include "../../x11/py-gnome2/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
