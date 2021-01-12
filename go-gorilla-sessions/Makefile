# $NetBSD$

DISTNAME=	go-gorilla-sessions-1.2.1
GITHUB_PROJECT=	sessions
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.gorillatoolkit.org/pkg/sessions
COMMENT=	Gorilla/sessions provides cookie and filesystem sessions
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gorilla/${GITHUB_PROJECT}

.include "../../wip/go-gorilla-securecookie/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
