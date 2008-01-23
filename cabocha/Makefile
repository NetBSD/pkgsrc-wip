# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 07:40:58 obache Exp $
#

DISTNAME=	cabocha-0.53
CATEGORIES=	devel
MASTER_SITES=	http://www.chasen.org/~taku/software/cabocha/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.chasen.org/~taku/software/cabocha/
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
