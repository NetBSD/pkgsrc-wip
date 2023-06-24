# $NetBSD: Makefile,v 1.1 2014/11/19 10:49:56 khorben Exp $

PKGNAME=	git-docs-html-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (HTML documentation)

DISTINFO_FILE=		../../devel/git-base/distinfo

TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=		c
BUILD_TARGET=		html
INSTALL_TARGET=		install-html

UNLIMIT_RESOURCES+=	datasize

USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
