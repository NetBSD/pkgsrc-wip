# $NetBSD: Makefile,v 1.2 2003/05/26 15:01:21 bmeurer Exp $

DISTNAME=		devhelp-0.6.0
CATEGORIES=		devel x11
MASTER_SITES=		http://devhelp.codefactory.se/download/ \
			ftp://ftp.codefactory.se/pub/software/devhelp/source/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://devhelp.codefactory.se/
COMMENT=		Documentation viewer based on GNOME2

DEPENDS+=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devhelp
	${INSTALL_DATA} ${WRKSRC}/misc/devhelp.el ${WRKSRC}/misc/devhelp.vim \
		${PREFIX}/share/examples/devhelp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devhelp
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog README TODO \
		${PREFIX}/share/doc/devhelp

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
