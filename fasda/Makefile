# $NetBSD$

DISTNAME=	fasda-0.1.5.62
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	5689a5949622336d00b74c223bfa8d3abc5e7864

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

DEPENDS=	stringtie>0:../../wip/stringtie

REPLACE_PYTHON=	Scripts/heatmap.py

LDFLAGS.SunOS+=	-lresolv
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
