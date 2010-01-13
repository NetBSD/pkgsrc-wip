# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 10:52:54 obache Exp $
#

.include "../../wip/cabocha/Makefile.common"

PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES+=	ruby

COMMENT=	CaboCha ruby module

BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ruby

post-extract:
	${RUN} cd ${WRKSRC}/swig; ${ENV} make ruby;

CABOCHA_LIBS_CMD=	${BUILDLINK_PREFIX.cabocha}/bin/cabocha-config --libs

pre-configure:
	${SED} -e "s|@CABOCHA_LIBS@|`${CABOCHA_LIBS_CMD}`|g" \
		${WRKSRC}/ruby/extconf.rb.in > ${WRKSRC}/ruby/extconf.rb

BUILDLINK_API_DEPENDS.cabocha+=	cabocha>=${PKGVERSION_NOREV}
.include "../../wip/cabocha/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
