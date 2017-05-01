# $NetBSD$

GITHUB_PROJECT=	byzanz
DISTNAME=	0.2.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/GNOME/byzanz/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/byzanz-0.2.1

GCONF_SCHEMAS+=	src/byzanz.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
