# $NetBSD: Makefile,v 1.4 2014/05/24 09:49:32 obache Exp $
#

.include "../../wip/marisa/Makefile.common"

CATEGORIES+=	ruby

COMMENT=	MARISA ruby module

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	bindings/ruby

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../wip/marisa/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
