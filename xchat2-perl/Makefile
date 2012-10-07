# $NetBSD: Makefile,v 1.5 2012/10/07 20:11:08 asau Exp $

PKG_DESTDIR_SUPPORT=	none

.include "../../chat/xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-perl-/}

COMMENT=	Perl scripting plugin for xchat

INSTALLATION_DIRS=	share/examples/xchat share/doc/xchat
DEPENDS+=		xchat>=2.0.0:../../chat/xchat

BUILD_DIRS=		plugins/perl

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--enable-perl
CONFIGURE_ARGS+=	--disable-python

USE_TOOLS+=		perl
REPLACE_PERL=		plugins/perl/alt_completion.pl

.include "../../lang/perl5/buildlink3.mk"

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/perl/alt_completion.pl \
		${PREFIX}/share/examples/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perl.html \
		${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perldocs.html \
		${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
