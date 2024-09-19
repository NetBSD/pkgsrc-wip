# $NetBSD: Makefile,v 1.4 2012/10/03 15:09:54 asau Exp $
#

GITHUB_PROJECT=	metasploit-framework
DISTNAME=	metasploit-framework-4.12.29
CATEGORIES=	security ruby
MASTER_SITES=	${MASTER_SITE_GITHUB:=rapid7/}

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://spool.metasploit.com/releases/
COMMENT=	Exploit-Framework for Penetration-Testing
LICENSE=	modified-bsd

SCRIPTS=	msfcli msfconsole msfd msfelfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

#Fix me for msfgui

NO_BUILD=	yes
USE_TOOLS+=	pax ln chmod

INSTALLATION_DIRS+=	${PKGNAME}
DATADIR=		${PREFIX}/${PKGNAME}

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
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${DATADIR}
.for f in ${SCRIPTS}
	${CHMOD} +x ${DESTDIR}${DATADIR}/${f}
	${LN} -s ${DESTDIR}${DATADIR}/${f} ${DESTDIR}${PREFIX}/bin
.endfor


.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
