# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:40 asau Exp $
#

DISTNAME=		autossh-1.4c
CATEGORIES=		security
MASTER_SITES=		http://www.harding.motd.ca/autossh/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mj@mjturner.net
HOMEPAGE=		http://www.harding.motd.ca/autossh/
COMMENT=		Monitor and automatically restart SSH sessions and tunnels
#LICENSE=		autossh

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-configure
SUBST_MESSAGE.destdir=	Reaplacing @DESTDIR@
SUBST_FILES.destdir+=	Makefile.in
SUBST_VARS.destdir=	DESTDIR

.include "../../mk/bsd.pkg.mk"
