# $NetBSD$

DISTNAME=	go-pcidb-0.5.0
GITHUB_PROJECT=	pcidb
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaypipes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jaypipes/pcidb/
COMMENT=	Small golang library for querying PCI database
LICENSE=	apache-2.0

GO_SRCPATH=	github.com/jaypipes/pcidb/
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/go-homedir/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
