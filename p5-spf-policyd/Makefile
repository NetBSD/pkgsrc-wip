# $NetBSD: Makefile,v 1.4 2014/08/13 20:02:17 shindenmorr Exp $
#

DISTNAME=	postfix-policyd-spf-perl-2.010
PKGNAME=	p5-policyd-spf-2.010
CATEGORIES=	mail
MASTER_SITES=	http://launchpad.net/postfix-policyd-spf-perl/trunk/release2.010/+download/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://launchpad.net/postfix-policyd-spf-perl/
COMMENT=	Basic Postfix policy engine for SPF checking
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-Mail-SPF-[0-9]*:../../mail/p5-Mail-SPF
DEPENDS+=		p5-NetAddr-IP-[0-9]*:../../net/p5-NetAddr-IP
REPLACE_PERL=		postfix-policyd-spf-perl
INSTALLATION_DIRS=	libexec

USE_LANGUAGES=	# none
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postfix-policyd-spf-perl ${DESTDIR}/${PREFIX}/libexec/postfix-policyd-spf-perl

.include "../../mk/bsd.pkg.mk"
