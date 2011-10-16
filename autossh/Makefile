# $NetBSD: Makefile,v 1.2 2011/10/16 12:27:04 ryo-on Exp $
#

DISTNAME=		autossh-1.4c
CATEGORIES=		security
MASTER_SITES=		http://www.harding.motd.ca/autossh/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mj@mjturner.net
HOMEPAGE=		http://www.harding.motd.ca/autossh/
COMMENT=		Monitor and automatically restart SSH sessions and tunnels
#LICENSE=		autossh

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_MESSAGE.destdir=	Reaplacing @DESTDIR@
SUBST_FILES.destdir+=	Makefile.in
SUBST_VARS.destdir=	DESTDIR

.include "../../mk/bsd.pkg.mk"
