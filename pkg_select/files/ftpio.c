/*	$NetBSD: ftpio.c,v 1.2 2005/03/17 08:45:29 imilh Exp $	*/

#include <sys/cdefs.h>
#ifndef lint
__RCSID("$NetBSD: ftpio.c,v 1.2 2005/03/17 08:45:29 imilh Exp $");
#endif

/* slightly modified version of ftpio.c with pkg_select integration */

/*-
 * Copyright (c) 2003 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Thomas Klausner.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright (c) 1999 Hubert Feyrer.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Hubert Feyrer for
 *      the NetBSD Project.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/types.h>
#include <sys/time.h>
#include <sys/poll.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <regex.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>
#include <unistd.h>
#ifdef EXPECT_DEBUG
#include <vis.h>
#endif

#include "pkg_select.h"

/*
 * Names of environment variables used to pass things to
 * subprocesses, for connection caching.
 */
#define PKG_FTPIO_COMMAND		"PKG_FTPIO_COMMAND"
#define PKG_FTPIO_ANSWER		"PKG_FTPIO_ANSWER"
#define PKG_FTPIO_CNT			"PKG_FTPIO_CNT"
#define PKG_FTPIO_CURRENTHOST		"PKG_FTPIO_CURRENTHOST"
#define PKG_FTPIO_CURRENTDIR		"PKG_FTPIO_CURRENTDIR"

#undef STANDALONE   /* define for standalone debugging */

/* File descriptors */
typedef struct {
    int command;
    int answer;
} fds;


#if EXPECT_DEBUG
static int	 expect_debug = 1;
#endif /* EXPECT_DEBUG */
static int	 needclose=0;
static int	 ftp_started=0;
static fds	 ftpio;
static int	 ftp_pid;
static char	 term[1024];
static char	 bold_on[1024];
static char	 bold_off[1024];
/* pkg_select addon */
static int store_expect = 0;
static int use_tar;

/* imported from lib/file.c */
static Boolean Verbose = 0;
/* This struct defines the leading part of a valid URL name */
typedef struct url_t {
	const char   *u_s;		/* the leading part of the URL */
	int     u_len;		/* its length */
}       url_t;

/* A table of valid leading strings for URLs */
static const url_t urls[] = {
	{"ftp://", 6},
	{"http://", 7},
	{NULL, 0}
};

static const char *pkgsrc_progress[] = PKGSRC_PROGRESS;

/*
 * Returns length of leading part of any URL from urls table, or -1
 */
int
URLlength(const char *fname)
{
	const url_t *up;
	int     i;

	if (fname != (char *) NULL) {
		for (i = 0; isspace((unsigned char) *fname); i++) {
			fname++;
		}
		for (up = urls; up->u_s; up++) {
			if (strncmp(fname, up->u_s, up->u_len) == 0) {
				return i + up->u_len;    /* ... + sizeof(up->u_s);  - HF */
			}
		}
	}
	return -1;
}

/*
 * Returns the host part of a URL
 */
const char *
fileURLHost(const char *fname, char *where, int maxlen)
{
	const char   *ret;
	int     i;

	assert(where != NULL);
	assert(maxlen > 0);

	if ((i = URLlength(fname)) < 0) {	/* invalid URL? */
		errx(EXIT_FAILURE, "fileURLhost called with a bad URL: `%s'", fname);
	}
	fname += i;
	/* Do we have a place to stick our work? */
	ret = where;
	while (*fname && *fname != '/' && --maxlen)
		*where++ = *fname++;
	*where = '\0';

	return ret;
}
/* end of import from lib/file.c */

/*
 * expect "str" (a regular expression) on file descriptor "fd", storing
 * the FTP return code of the command in the integer "ftprc". The "str"
 * string is expected to match some FTP return codes after a '\n', e.g.
 * "\n(550|226).*\n" 
 */
static int
expect(int fd, const char *str, int *ftprc)
{
	int rc;
	char *p, buf[90], progress_str[90];
	char tmp[MAXLEN];
#if EXPECT_DEBUG
	char *vstr;
#endif /* EXPECT_DEBUG */
	regex_t rstr;
	int done;
	struct pollfd set[1];
	int retval;
	regmatch_t match;
	int verbose_expect=0;
	static int next = 1;

#if EXPECT_DEBUG
	vstr=malloc(2*sizeof(buf));
	if (vstr == NULL)
		err(EXIT_FAILURE, "expect: malloc() failed");
	strvis(vstr, str, VIS_NL|VIS_SAFE|VIS_CSTYLE);
#endif /* EXPECT_DEBUG */
	    
	if (regcomp(&rstr, str, REG_EXTENDED) != 0)
		err(EXIT_FAILURE, "expect: regcomp() failed");

#if EXPECT_DEBUG
	if (expect_debug)
		printf("expecting \"%s\" on fd %d ...\n", vstr, fd);
#endif /* EXPECT_DEBUG */

	if(0) setbuf(stdout, NULL);

	memset(buf, '\n', sizeof(buf));

	done=0;
	retval=0;
	set[0].fd = fd;
	set[0].events = POLLIN;
	while(!done) {
		rc = poll(set, 1, 10*60*1000);    /* seconds until next message from tar */
		switch (rc) {
		case -1:
			if (errno == EINTR)
				break;
			warn("expect: poll() failed (probably ftp died because of bad args)");
			done = 1;
			retval = -1;
			break;
		case 0:
			warnx("expect: poll() timeout");
			/* need to send ftp coprocess SIGINT to make it stop
			 * downloading into dir that we'll blow away in a second */
			kill(ftp_pid, SIGINT);

			/* Wait until ftp coprocess is responsive again 
			 * XXX Entering recursion here!
			 */
			rc = ftp_cmd("cd .\n", "\n(550|250).*\n");
			if (rc != 250) {
				/* now we have a really good reason to bail out ;) */
			}
			/* ftp is at command prompt again, and will wait for our
			 * next command. If we were downloading, we can now safely
			 * continue and remove the dir that the tar command was
			 * expanding to */
		    
			done = 1;	/* hope that's ok */
			retval = -1;
			break;
		default:
			if (set[0].revents & POLLHUP) {
				done = 1;
				retval = -1;
				break;
			}

			rc = read(fd, &buf[sizeof(buf) - 1], 1);
			if (rc <= 0) {
				done = 1;
				retval = -1;
				break;
			}

			
			if (verbose_expect)
				putchar(buf[sizeof(buf)-1]);

#if EXPECT_DEBUG
			{
				char *v=malloc(2*sizeof(buf));
				strvis(v, buf, VIS_NL|VIS_SAFE|VIS_CSTYLE);
				if (expect_debug)
					printf("expect=<%s>, buf=<%*s>\n", vstr, strlen(v), v);
				free(v);
			}
#endif /* EXPECT_DEBUG */
			
			/******************pkg_select mess !******************/
			if (store_expect) {
				int len;

				XSTRCPY(tmp, buf);
				len = strlen(tmp) - 1;
				/* line finished with a \n, 
				 * must be a full line
				 * point then to last ' ' and ++
				 */
				if (tmp[len] == '\n') {
					tmp[len] = '\0';
					if ((p = strrchr(tmp, '\n')) != NULL) {
						p++;
						/* callback */
						fill_store(p);
					}
				}
			} /* was not a store request */

			/* used for progress bars with tar(1) */
			if (use_tar && strncmp(buf, "pkgsrc/", 7) == 0 &&
			    (p = strchr(buf, '/')) != NULL) {
				p++; /* point after pkgsrc/ */
				strcpy(progress_str, p);
				if ((p = strchr(progress_str, '/')) != NULL) {
					/* pkg_select addon */
					if (conf.shell_output)
						printf("%s\n", progress_str);
					else if (next) {
						char msg[MAXLEN];
						p++;
						*p = '\0';

						snprintf(msg, MAXLEN,
							 "extracting %s",
							 progress_str);
						next = progress_bar(pkgsrc_progress, 
								    msg, 
								    INCREMENTAL);
					}
				} /* extract category from path */
			} /* strcmp pkgsrc/ (tar progress) */


			if (regexec(&rstr, buf, 1, &match, 0) == 0) {
#if EXPECT_DEBUG
				if (expect_debug)
					printf("Gotcha -> %s!\n", buf+match.rm_so+1);
				fflush(stdout);
#endif /* EXPECT_DEBUG */

				if (ftprc && 
				    isdigit((unsigned char)buf[match.rm_so+1])) 
					*ftprc = atoi(buf+match.rm_so+1);

				done=1;
				retval=0;
			}
	    
			memmove(buf, buf+1, sizeof(buf)-1); /* yes, this is non-performant */			
			break;
		} /* switch rc */
	}

#if EXPECT_DEBUG
	printf("done.\n");

	if (str)
		free(vstr);
#endif /* EXPECT_DEBUG */

	return retval;
}

/*
 * send a certain ftp-command "cmd" to our FTP coprocess, and wait for
 * "expectstr" to be returned. Return numeric FTP return code or -1
 * in case of an error (usually expect() timeout) 
 */
int
ftp_cmd(const char *cmd, const char *expectstr)
{
	int rc=0, verbose_ftp=0;
	int len;
	/* pkg_select adddon */
	char wcmd[MIDLEN], *p;

	XSTRCPY(wcmd, cmd);
	if (cmd != NULL && (p = strstr(wcmd, STORE_EXPECT)) != NULL) {
		p--; /* point to : */
		*p = '\0';
		store_expect = 1;
	} else
		store_expect = 0;

	if (strstr(wcmd, TAR_CMD) != NULL)
		use_tar = 1;
	else
		use_tar = 0;

	if (Verbose)
		verbose_ftp=1;
    
	if (verbose_ftp)
		fprintf(stderr, "\n%sftp> %s%s", bold_on, wcmd, bold_off);

	fflush(stdout);
	len = write(ftpio.command, wcmd, strlen(wcmd));
	if ((unsigned int)len == strlen(wcmd)) {
		if (expectstr) {
			/* set "rc" to the FTP error code: */
			if (expect(ftpio.answer, expectstr, &rc) == -1)
				rc = -1;	/* some error occurred */
		}
	} else {	
		if (Verbose)
			warn("short write");
	}

	return rc;
}


/*
 * Really fire up FTP coprocess
 */
static int
setupCoproc(const char *base)
{
	int command_pipe[2];
	int answer_pipe[2];
	int rc1, rc2;
	char buf[20];
	const char *argv0 = strrchr(FTP_CMD, '/');
	if (argv0 == NULL)
		argv0 = FTP_CMD;
	else
		argv0++;

	rc1 = pipe(command_pipe);
	rc2 = pipe(answer_pipe);

	if(rc1==-1 || rc2==-1) {
		warn("setupCoproc: pipe() failed");
		return -1;
	}

	if (command_pipe[0] == -1 || command_pipe[1] == -1 ||
	    answer_pipe[0] == -1  || answer_pipe[1] == -1 ) {
		warn("setupCoproc: pipe() returned bogus descriptor");
		return -1;
	}

	rc1 = fork();
	switch (rc1) {
	case -1:
		/* Error */
	    
		warn("setupCoproc: fork() failed");
		return -1;
		break;

	case 0:
		/* Child */
	    
		(void) close(command_pipe[1]);
		rc1 = dup2(command_pipe[0], 0);
		if (rc1 == -1) {
			err(EXIT_FAILURE, "setupCoproc: dup2 failed (command_pipe[0])");
		}
		(void) close(command_pipe[0]);
	    
		(void) close(answer_pipe[0]);
		rc1 = dup2(answer_pipe[1], 1);
		if (rc1 == -1) {
			err(EXIT_FAILURE, "setupCoproc: dup2 failed (answer_pipe[1])");
		}
		(void) close(answer_pipe[1]);
	    
		setbuf(stdout, NULL);
	    
		if (Verbose)
			fprintf(stderr, "%sftp -detv %s%s\n", bold_on, base, bold_off);
		/* pkg_select addon */
		/* we deal with curses, don't really want 
		   stderr to mess display */
		close(2);
		rc1 = execlp(FTP_CMD, argv0, "-detv", base, NULL);
		warn("setupCoproc: execlp() failed");
		exit(1);
		break;
	default: 
		/* Parent */
		(void) close(command_pipe[0]);
		(void) close(answer_pipe[1]);
	    
		(void) snprintf(buf, sizeof(buf), "%d", command_pipe[1]);
		setenv(PKG_FTPIO_COMMAND, buf, 1);
		(void) snprintf(buf, sizeof(buf), "%d", answer_pipe[0]);
		setenv(PKG_FTPIO_ANSWER, buf, 1);
	    
		ftpio.command = command_pipe[1];
		ftpio.answer  = answer_pipe[0];
		ftp_pid = rc1;			/* to ^C transfers */
	    
		fcntl(ftpio.command, F_SETFL, O_NONBLOCK);
		fcntl(ftpio.answer , F_SETFL, O_NONBLOCK);
	    
		break;
	}

	return 0;
}


/*
 * Dummy signal handler to detect if the ftp(1) coprocess or
 * and of the processes of the tar/gzip pipeline dies. 
 */
static void
sigchld_handler (int n)
{
	/* Make poll(2) return EINTR */
	/* do something, avoid warnings */
	n &= 0;
}


/*
 * SIGPIPE only happens when there's something wrong with the FTP
 * coprocess. In that case, set mark to not try to close shut down
 * the coprocess.
 */
static void
sigpipe_handler(int n)
{
	/* do something, avoid warnings */
	n &= 0;
	/* aparently our ftp companion died */
	if (Verbose)
		fprintf(stderr, "SIGPIPE!\n");
	needclose = 0;
}


/*
 * Close the FTP coprocess' current connection, but
 * keep the process itself alive. 
 */
void 
ftp_stop(void)
{
#if defined(__svr4__) && defined(__sun__)
	char	env[BUFSIZ];
#endif
	const char *tmp1, *tmp2;
	
	if (!ftp_started)
		return;
	
	tmp1=getenv(PKG_FTPIO_COMMAND);
	tmp2=getenv(PKG_FTPIO_ANSWER);
	
	/* (Only) the last one closes the link */
	if (tmp1 != NULL && tmp2 != NULL) {
		if (needclose)
			ftp_cmd("close\n", "\n(221 .*|Not connected.)\n");
		
		(void) close(ftpio.command);
		(void) close(ftpio.answer);
	}

#if defined(__svr4__) && defined(__sun__)
	(void) snprintf(env, sizeof(env), "%s=", PKG_FTPIO_COMMAND);
	putenv(env);
	(void) snprintf(env, sizeof(env), "%s=", PKG_FTPIO_ANSWER);
	putenv(env);
#else
	unsetenv(PKG_FTPIO_COMMAND); 
	unsetenv(PKG_FTPIO_ANSWER);
#endif
}


/*
 * (Start and re-)Connect the FTP coprocess to some host/dir.
 * If the requested host/dir is different than the one that the
 * coprocess is currently at, close first. 
 */
int
ftp_start(const char *base)
{
	const char *tmp1, *tmp2;
	char *p;
	int rc;
	char newHost[MAXHOSTNAMELEN];
	const char *newDir;
	const char *currentHost=getenv(PKG_FTPIO_CURRENTHOST);
	const char *currentDir=getenv(PKG_FTPIO_CURRENTDIR);
	int urllen;

	/* talk to termcap for bold on/off escape sequences */
	if (getenv("TERM") != NULL && tgetent(term, getenv("TERM")) > 0) {
		p = bold_on;  tgetstr("md", &p);
		p = bold_off; tgetstr("me", &p);
	} else {
		bold_on[0]  = '\0';
		bold_off[0] = '\0';
	}
	
	fileURLHost(base, newHost, sizeof(newHost));
	urllen = URLlength(base);
	if (urllen < 0 || !(newDir = strchr(base + URLlength(base), '/')))
		errx(EXIT_FAILURE, "ftp_start: bad URL '%s'", base);
	newDir++;
	if (currentHost
	    && currentDir
	    && ( strcmp(newHost, currentHost) != 0
		 || strcmp(newDir, currentDir) != 0)) { /* could handle new dir case better here, w/o reconnect */
		if (Verbose) {
			printf("ftp_start: new host or dir, stopping previous connect...\n");
			printf("currentHost='%s', newHost='%s'\n", currentHost, newHost);
			printf("currentDir='%s', newDir='%s'\n", currentDir, newDir);
		}
		
		ftp_stop();
		
		if (Verbose)
			printf("ftp stopped\n");
	}
	setenv(PKG_FTPIO_CURRENTHOST, newHost, 1); /* need to update this in the environment */
	setenv(PKG_FTPIO_CURRENTDIR, newDir, 1);   /* for subprocesses to have this available */
	
	tmp1=getenv(PKG_FTPIO_COMMAND);
	tmp2=getenv(PKG_FTPIO_ANSWER);
	if(tmp1==NULL || tmp2==NULL || *tmp1=='\0' || *tmp2=='\0') {
		/* no FTP coprocess running yet */
		
		if (Verbose)
			printf("Spawning FTP coprocess\n");
		
		rc = setupCoproc(base);
		if (rc == -1) {
			warnx("setupCoproc() failed");
			return -1;
		}
		
		needclose=1;
		signal(SIGPIPE, sigpipe_handler);
		signal(SIGCHLD, sigchld_handler);

		if ((expect(ftpio.answer, "\n(221|250|221|550).*\n", &rc) != 0)
		    || rc != 250) {
			warnx("expect1 failed, rc=%d", rc);
			return -1;
		}
		
		/* nbftp now issues a CWD for each part of the path
		 * and will return a code for each of them. No idea how to
		 * deal with that other than to issue a 'prompt off' to
		 * get something that we can wait for and that does NOT
		 * look like a CWD command's output */
		rc = ftp_cmd("prompt off\n", "\n(Interactive mode off|221).*\n");
		if ((rc == 221) || (rc == -1)) {
			/* something is wrong */
			ftp_started=1; /* not really, but for ftp_stop() */
			ftp_stop();
			warnx("prompt failed - wrong dir?");
			return -1;
		}
		
		ftp_started=1;
	} else {
		/* get FDs of our coprocess */
		
		ftpio.command = dup(atoi(tmp1));
		if (ftpio.command == -1 ) {
			warnx("command dup() failed, increase 'descriptors' limit");
			return -1;
		}
		ftpio.answer  = dup(atoi(tmp2));
		if (ftpio.answer == -1 ) {
			warnx("answer dup() failed, increase 'descriptors' limit");
			return -1;
		}
		
		if (Verbose)
			printf("Reusing FDs %s/%s for communication to FTP coprocess\n", tmp1, tmp2);
		
		fcntl(ftpio.command, F_SETFL, O_NONBLOCK);
		fcntl(ftpio.answer , F_SETFL, O_NONBLOCK);
	}
	
	return 0;
}
