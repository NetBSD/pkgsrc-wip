# $NetBSD: Makefile,v 1.2 2005/06/06 12:37:25 minskim Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-perl-/}

COMMENT=	Perl scripting plugin for xchat

DEPENDS+=	xchat>=2.0.0:../../chat/xchat

BUILD_DIRS?=	${WRKSRC}/plugins/perl

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--enable-perl
CONFIGURE_ARGS+=	--disable-python

USE_PERL5=	YES
REPLACE_PERL=	plugins/perl/sample_script.pl plugins/perl/ignore.pl

.include "../../lang/perl5/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/xchat
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/perl/sample_script.pl \
		${PREFIX}/share/examples/xchat
	${INSTALL_SCRIPT} ${WRKSRC}/plugins/perl/ignore.pl \
		${PREFIX}/share/examples/xchat
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perl.html \
		${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/plugins/perl/xchat2-perldocs.html \
		${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
