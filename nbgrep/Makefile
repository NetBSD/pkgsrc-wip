# $NetBSD: Makefile,v 1.1.1.1 2003/08/23 20:15:06 cjep Exp $
# From: pkgsrc/textproc/bsdgrep 
# NetBSD: Makefile,v 1.3 2003/06/02 01:16:44 jschauma Exp 

DISTNAME=	nbgrep-20030823
CATEGORIES=	sysutils textproc wip
MASTER_SITES=	http://www.fawlty.net/software/

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	# none
COMMENT=	BSD version of grep as in NetBSD othersrc

CONFLICTS+=		bsdgrep-*
#ONLY_FOR_PLATFORM=	NetBSD-1.6*-*

post-patch:
	@${SED} -e 's|grep|bgrep|g' ${WRKSRC}/grep.1 > ${WRKSRC}/bgrep.1

.include "../../mk/bsd.pkg.mk"
