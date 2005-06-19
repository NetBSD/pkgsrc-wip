# $NetBSD: Makefile,v 1.1.1.1 2005/06/19 22:21:20 hisazumi Exp $

DISTNAME=		metalog-0.8-rc1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=metalog/}

MAINTAINER=             nel@soraneko.com
HOMEPAGE=               http://metalog.sourceforge.net/
COMMENT=                Metalog is a modern replacement for syslogd and klogd

DEPENDS+=		pcre:../../devel/pcre

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include	"../../devel/pcre/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
