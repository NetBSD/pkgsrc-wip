# $NetBSD: Makefile,v 1.1 2007/10/25 19:28:36 bsadewitz Exp $
#

DISTNAME=	tig-0.9.1
CATEGORIES=	devel scm
MASTER_SITES=	http://jonas.nitro.dk/tig/releases/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://jonas.nitro.dk/tig/releases/
COMMENT=	GIT repository browser

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

DEPENDS+=	scmgit-[0-9]*:../../devel/scmgit

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake gmake

CONFIGURE_ARGS+=		${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=${BUILDLINK_PREFIX.iconv}

BUILD_TARGET=	all doc
INSTALL_TARGET=	install install-doc

pre-configure:
	cd ${WRKSRC} && autoreconf -v --install

.include "../../devel/ncurses/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
