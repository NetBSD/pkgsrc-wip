# $NetBSD: Makefile,v 1.2 2009/08/15 01:26:07 prudhvikrishna Exp $
#

DISTNAME=	framework-3.2
PKGNAME=	metasploit-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://spool.metasploit.com/releases/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://spool.metasploit.com/releases/
COMMENT=	Exploit-Framework for Penetration-Testing
LICENSE=	modified-bsd

SCRIPTS=	msfcli msfconsole msfd msfelfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

#Fix me for msfgui

PKG_DESTDIR_SUPPORT+=	user-destdir
NO_BUILD=	yes
USE_TOOLS+=	pax ln chmod

INSTALLATION_DIRS+=	${PKGNAME}
DATADIR=	${DESTDIR}${PREFIX}/${PKGNAME}

REPLACE_RUBY+=	${SCRIPTS} \
		data/msfweb/vendor/rails/actionpack/lib/action_controller/session/drb_server.rb \
		data/msfweb/vendor/rails/railties/dispatches/dispatch.fcgi \
		data/msfweb/vendor/rails/railties/dispatches/dispatch.rb \
		data/msfweb/vendor/rails/railties/dispatches/gateway.cgi \
		data/msfweb/vendor/rails/railties/lib/commands/ncgi/listener \
		data/msfweb/vendor/rails/railties/lib/commands/ncgi/tracker \
		data/msfweb/public/dispatch.cgi \
		data/msfweb/public/dispatch.fcgi \
		data/msfweb/public/dispatch.rb \
		external/pcaprub/test_pcaprub.rb \
		lib/metasm/samples/linux_injectsyscall.rb \
		lib/ole/support.rb \
		lib/ole/storage.rb

REPLACE_PERL+=	lib/rex/post/gen.pl \
		external/source/shellcode/windows/build.sh
pre-patch:
	${FIND} ${WRKSRC} -iname ".svn" -print | ${XARGS} rm -fdr
	${FIND} ${WRKSRC} -type f -exec chmod a-x {} \;

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DATADIR}
.for f in ${SCRIPTS}
	${CHMOD} +x ${DATADIR}/${f}
	${LN} -s ${DATADIR}/${f} ${DESTDIR}${PREFIX}/bin
.endfor


.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
