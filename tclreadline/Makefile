# $NetBSD: Makefile,v 1.1.1.1 2008/12/09 22:58:43 pettai Exp $
#

DISTNAME=	tclreadline-2.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclreadline/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://tclreadline.sourceforge.net/
COMMENT=	GNU Readline library for interactive tcl shells

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib

EGDIR=		${PREFIX}/share/examples/tclreadline

PKG_DESTDIR_SUPPORT=	user-destdir

MESSAGE_SUBST+=		EGDIR=${EGDIR}

INSTALLATION_DIRS=	include ${PKGMANDIR}/mann lib \
			lib/tclreadline${PKGVERSION} ${EGDIR}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/tclshrc ${DESTDIR}${EGDIR}/tclshrc

.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
