# $NetBSD$

PKGNAME=	self
CATEGORIES=	lang
GIT_REPO=	http://github.com/russellallen/self.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rui314/8cc/
COMMENT=	Prototype-based dynamic object-oriented programming language
LICENSE=	# BSD

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

BUILDLINK_TRANSFORM+=	rm:-O2

.include "../../wip/mk/git-package.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
