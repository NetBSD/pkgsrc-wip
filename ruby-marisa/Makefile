# $NetBSD: Makefile,v 1.1 2013/11/04 01:01:32 ishit Exp $
#

.include "../../wip/marisa/Makefile.common"

#CATEGORIES+=	ruby

COMMENT=	MARISA ruby module

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	bindings/ruby

#marisa_LIBS_CMD=	${BUILDLINK_PREFIX.marisa}/bin/marisa-config --libs
#
#post-extract:
#	${SED} -e "s|@marisa_LIBS@|`${marisa_LIBS_CMD}`|g" \
#		${WRKSRC}/ruby/extconf.rb.in > ${WRKSRC}/ruby/extconf.rb

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../wip/marisa/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
