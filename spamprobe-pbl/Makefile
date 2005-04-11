# $NetBSD: Makefile,v 1.3 2005/04/11 21:15:54 tvierling Exp $

DISTNAME=	spamprobe-0.9h
PKGNAME=	spamprobe-pbl-0.9h
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

CONFLICTS=	spamprobe-[0-9]*

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-default-8bit
CONFIGURE_ARGS+=	--with-pbl=${BUILDLINK_PREFIX.pbl}

.include "../../wip/pbl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
