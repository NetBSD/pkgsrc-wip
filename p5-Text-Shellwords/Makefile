# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 21:54:57 daprice Exp $
#

DISTNAME=		Text-Shellwords-1.02
PKGNAME=		p5-${DISTNAME}
WRKSRC=                 ${WRKDIR}/Text-Shellwords-1.02
CATEGORIES=		textproc
MASTER_SITES=		http://www.cpan.org/authors/id/L/LD/LDS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.cpan.org/authors/id/L/LD/LDS/
COMMENT=		Wrapper around shellwords.pl package

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Text/Shellwords/.packlist

pre-build:
	cd ${WRKSRC}; perl Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
