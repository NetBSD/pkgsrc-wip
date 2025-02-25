# $NetBSD$

DISTNAME=	fasda-0.1.5.34
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	16ede6f148679dfb0877a76bb3963c4d7917a649

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

DEPENDS=	stringtie>0:../../wip/stringtie

LDFLAGS.SunOS+=	-lresolv
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
