# $NetBSD: Makefile,v 1.4 2013/05/07 14:42:58 jgoamakf Exp $
#

DISTNAME=	HTML-WebMake-2.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://webmake.taint.org/devel/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://webmake.taint.org/
COMMENT=	WebMake is a simple web site management system

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Text-EtText-[0-9]*:../../wip/p5-Text-EtText
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-XML-Sablotron-[0-9]*:../../textproc/p5-XML-Sablotron
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size

PERL5_PACKLIST=		auto/HTML/WebMake/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
