# $NetBSD: Makefile,v 1.2 2011/10/12 09:04:45 jgoamakf Exp $
#

DISTNAME=		String-Similarity-1.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Similarity/
COMMENT=		Calculate the similarity of two strings
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGE=		c
PERL5_PACKLIST=		auto/String/Similarity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
