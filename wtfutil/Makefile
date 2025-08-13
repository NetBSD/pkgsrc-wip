# $NetBSD$

DISTNAME=	wtfutil-0.46.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wtfutil/}
GITHUB_PROJECT=	wtf
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wtfutil.com/
COMMENT=	The terminal dashboard
LICENSE=	mpl-2.0

# Avoid godbus/dbus dependency that is not supported by NetBSD.
post-extract:
	${RM} -rf ${WRKSRC}/modules/spotify

# Avoid conflicts with wtf(6)
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/wtf ${DESTDIR}${PREFIX}/bin/wtfutil

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
