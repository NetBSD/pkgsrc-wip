# $NetBSD: Makefile,v 1.1.1.1 2007/02/27 22:54:17 dzoe Exp $
#

DISTNAME=		uptimed-0.3.10
CATEGORIES=		sysutils
MASTER_SITES=		http://podgorny.cz/uptimed/releases/
EXTRACT_SUFX=   	.tar.bz2

MAINTAINER=		joe@joe.cz
HOMEPAGE=		http://podgorny.cz/uptimed/
COMMENT=		Keeps track of current and past system uptimes

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

RCD_SCRIPTS=            uptimed
CONF_FILES=		etc/uptimed.conf-dist etc/uptimed.conf

.include "../../mk/bsd.pkg.mk"
