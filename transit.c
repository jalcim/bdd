#include "transit_bdd.h"

void print_struct();
int main()
{
	init_transit(0);
	init_transit(4);
	init_data(0);
	init_data(4);
	if (!fork())
    {
		transit("jalcim", "test 0");
		transit("jalcim", "test 1");
		transit("jalcim", "test 2");
		transit("jalcim", "test 3");
		transit("jalcim", "test 4");
		transit("jalcim", "test 5");
		transit("jalcim", "test 6");
		transit("jalcim", "test 7");
		transit("jalcim", "test 8");
		transit("jalcim", "test 9");

		transit("jalcim", "test 10");
		transit("jalcim", "test 11");
		transit("jalcim", "test 12");
		transit("jalcim", "test 13");
		transit("jalcim", "test 14");
		transit("jalcim", "test 15");
		transit("jalcim", "test 16");
		transit("jalcim", "test 17");
		transit("jalcim", "test 18");
		transit("jalcim", "test 19");

		transit("GRUM", "test 20");
		transit("GRUM", "test 21");
		transit("GRUM", "test 22");
		transit("GRUM", "test 23");
		transit("GRUM", "test 24");
		transit("GRUM", "test 25");
		transit("GRUM", "test 26");
		transit("GRUM", "test 27");
		transit("GRUM", "test 28");
		transit("GRUM", "test 29");

		transit("GRIIIM", "test 30");
		transit("GRIIIM", "test 31");
		transit("GRIIIM", "test 32");
		transit("GRIIIM", "test 33");
		transit("GRIIIM", "test 34");
		transit("GRIIIM", "test 35");
		transit("GRIIIM", "test 36");
		transit("GRIIIM", "test 37");
		transit("GRIIIM", "test 38");
		transit("GRIIIM", "test 39");

		transit("jalci", "test 40");
		transit("jalci", "test 41");
		transit("jalci", "test 42");
		transit("jalci", "test 43");
		transit("jalcm", "test 44");
		transit("jalcm", "test 45");
		transit("jalcm", "test 46");
		transit("jalci", "test 47");
		transit("jalcim", "test 48");
		transit("jalcim", "test 49");
		exit(0);
    }
	sleep(1);
  synch_data();
  printf("ok\n");
  sleep(2);
  print_struct();  
  return (0);
}

int transit(char *login, char *buffer)
{
	int *pipefd;
  
  if (!(pipefd = recup_pipefd(NULL)))
	  printf("error\n");
  write(pipefd[1], login, strlen(login));
  write(pipefd[1], "\0", 1);
  write(pipefd[1], buffer, strlen(buffer));
  write(pipefd[1], "\0", 1);
  return (0);
}

int print_str_struct(t_datalist *data);
void print_struct()
{
	t_datalist *data;
	int b = 1;

	printf("print_struct\n");
	data = recup_datalist(NULL);
	while (data->prev)
    {
		printf("prev\n\n"); 
		data = data->prev;
    }
	while (b)
    {
		while (print_str_struct(data))
		{}
		data->cpt_read = 0;
		if (data->next)
		{
			printf("next\n\n");
			data = data->next;
		}
		else
			b = 0;
    }
	printf("print_struct out\n");
}

int print_str_struct(t_datalist *data)
{
	if (data->cpt_read >= data->cpt_max)
		return (0);
	if (!data->login)
	{
		printf("pas d'login\n");
		exit(-1);
	}
	if (!data->data[data->cpt_read])
	{
		printf("error structure\n");
		exit(-1);
	}
	printf("login :%s: chat conv[%d] sur [%d]= :%s:\n", 
		   data->login, data->cpt_read, data->cpt_max, data->data[data->cpt_read]);
	printf(":%p:\n\n", data->data[data->cpt_read]);
	data->cpt_read++;
	return (1);
}
