# $NetBSD: Makefile,v 1.2 2010/01/13 10:49:51 obache Exp $
#

.include "Makefile.common"

COMMENT=	Yet another Japanese Dependency Structure Analyzer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
CONFIGURE_ARGS+=	--with-morphological-analyzer=chasen

INSTALL_MAKE_FLAGS+=	confdir=${PREFIX}/share/examples

CONF_FILES=	share/examples/cabocharc ${PKG_SYSCONFDIR}/cabocharc

TEST_TARGET=	check

BUILD_DEPENDS+=	nkf-[0-9]*:../../converters/nkf

.include "../../wip/yamcha/buildlink3.mk"
.include "../../textproc/chasen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
