# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 10:47:52 obache Exp $
#

.include "../../wip/yamcha/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES+=	ruby

COMMENT=	YamCha ruby module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

YAMCHA_LIBS_CMD=	${BUILDLINK_PREFIX.yamcha}/bin/yamcha-config --libs

post-extract:
	${SED} -e "s|@YAMCHA_LIBS@|`${YAMCHA_LIBS_CMD}`|g" \
		${WRKSRC}/ruby/extconf.rb.in > ${WRKSRC}/ruby/extconf.rb

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../wip/yamcha/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
