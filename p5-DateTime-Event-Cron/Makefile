# $NetBSD: Makefile,v 1.1.1.1 2003/06/17 12:46:42 cubidou Exp $

DISTNAME=		DateTime-Event-Cron-0.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Event-Cron/
COMMENT=		DateTime extension to handle crontab entries 

DEPENDS+=		p5-DateTime-Set-[0-9]*:../../wip/p5-DateTime-Set
DEPENDS+=		p5-Set-Crontab-[0-9]*:../../wip/p5-Set-Crontab

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DateTime/Event/Cron/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
