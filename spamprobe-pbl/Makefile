# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 14:52:59 oherrala Exp $

DISTNAME=	spamprobe-0.9g2
PKGNAME=	spamprobe-pbl-0.9g2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

CONFLICTS=	spamprobe-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-default-8bit
CONFIGURE_ARGS+=	--with-pbl=${BUILDLINK_PREFIX.pbl}

.include "../../wip/pbl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
