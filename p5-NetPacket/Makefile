# $NetBSD: Makefile,v 1.2 2004/05/02 21:44:05 blef Exp $

DISTNAME=	NetPacket-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=NetPacket/}

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Modules to assemble/disassemble network packets

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NetPacket/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
