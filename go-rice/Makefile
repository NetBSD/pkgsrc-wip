# $NetBSD$

DISTNAME=	go-rice-1.0.2
GITHUB_PROJECT=	go.rice
PKGREVISION=	2
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=GeertJohan/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/GeertJohan/go.rice/
COMMENT=	Working with resources such as html,js,css,images,templates
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/GeertJohan/go.rice

.include "../../devel/go-spew/buildlink3.mk"
.include "../../wip/go-fastprinter/buildlink3.mk"
.include "../../wip/go-fasttemplate/buildlink3.mk"
.include "../../wip/go-flags/buildlink3.mk"
.include "../../wip/go-incremental/buildlink3.mk"
.include "../../wip/go-rsrc/buildlink3.mk"
.include "../../wip/go-streamquote/buildlink3.mk"
.include "../../wip/go-zipexe/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
