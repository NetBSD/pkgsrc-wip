# $NetBSD: Makefile,v 1.3 2010/02/11 11:09:49 obache Exp $
#

.include "Makefile.common"

COMMENT=	Yet another Japanese Dependency Structure Analyzer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run gzcat

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

INSTALL_MAKE_FLAGS+=	confdir=${PREFIX}/share/examples

CONF_FILES=	share/examples/cabocharc ${PKG_SYSCONFDIR}/cabocharc

TEST_TARGET=	check

BUILD_DEPENDS+=	nkf-[0-9]*:../../converters/nkf

# using zcat to extract .gz
SUBST_CLASSES+=		zcat
SUBST_STAGE.zcat=	post-configure
SUBST_FILES.zcat=	model/Makefile
SUBST_SED.zcat=		-e 's|zcat|${TOOLS_CMDLINE_GZCAT}|g'

.include "options.mk"

.include "../../wip/yamcha/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
