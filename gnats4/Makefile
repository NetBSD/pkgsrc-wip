# $NetBSD: Makefile,v 1.4 2004/01/25 02:22:44 grantbeattie Exp $
#

DISTNAME=	gnats-4.0
CATEGORIES=	databases
MASTER_SITES=	http://home.pacific.net.au/~meganandaj/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS bug tracking system

BUILD_DEPENDS+=	m4-*:../../devel/m4

CONFLICTS=	gnats-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_BISON=		yes
USE_MAKEINFO=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

INFO_FILES=	gnats.info gnats-faq.info

CONFIGURE_ARGS= --with-lispdir=${PREFIX}/share/emacs/site-lisp

GNATS_HOME=	${PREFIX}/share/gnats/gnats-db
PKG_USERS=	gnats:daemon::GNATS\\ database\\ owner:${GNATS_HOME}:${SH}

MAKE_DIRS=		${PREFIX}/share/gnats
MAKE_DIRS+=		${PREFIX}/libexec/gnats
OWN_DIRS_PERMS=		${GNATS_HOME} gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-queue gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/pending gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm/locks gnats daemon 755

MESSAGE_SUBST+=		PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
